#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

#define TRUE 1  // because shitty programming language or a shitty programmer

int main(int argc, char *argv[]) {
    int num_of_processes, global_rank, rc;
    MPI_Comm split_comm_world;  // Different comm_world to segregate master and slaves

    //Variables for Cartesian Comm handler
    MPI_Comm cart_comm_world;   // Cartesian topology comm_world for WSN communications
    int cart_rank;  // rank for cart_comm_world
    int periodic[] = {0,0}; // Topology wrap-around is not required. False for both dimensions
    int dims[2] = {4,5};    // 2 Dimensions for cartesian topology. 4 Rows, 5 Columns
    int left, right, up, down;  // Adjacent processes from process in cartesian grid.

    // Variable for sends and receives
    int msg_send_phase = 0; //Counter for how many phases of data exchange
    int data;  // Variable to simulate a sensor detection
    int recv_data[4] = {-1, -1, -1, -1}; // Data received from adjacent nodes. Represents {left, right, up, down}
    int i;  // Generic Variable for loops
    int req_count = 0;      // Point to current empty position of the reqs array
    MPI_Request reqs[8];   // Up to 4 receives and 4 sends are posted at every phase. 8 MPI_requests monitors are required
    MPI_Status msg_status[8];  // MPI_status for all 8 send receive operations
    int termination[4] = {-5,-5,-5,-5}; // Dirty variable to send a termination message to Master Node. Design and explanation in documentation

    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &num_of_processes);
    MPI_Comm_rank(MPI_COMM_WORLD, &global_rank);


    //Split the comm world 2 groups. One with master(rank 0), and the other group for slaves processes(1 to 20)
    MPI_Comm_split(MPI_COMM_WORLD, global_rank == 0, 0, &split_comm_world);

    if (global_rank == 0) {     //Master node
        master_standby_recv(MPI_COMM_WORLD);
    }
    else {  //Slaves nodes
        MPI_Cart_create(split_comm_world, 2, dims, periodic, 1, &cart_comm_world);
        MPI_Cart_shift(cart_comm_world, 1, 1, &left, &right);
        MPI_Cart_shift(cart_comm_world, 0, 1, &up, &down);
        MPI_Comm_rank(cart_comm_world, &cart_rank);

        srand((cart_rank*MPI_Wtime()));   // Create a PRNG for each slave, using time * rank as the random seed
    }

    // Start the data exchange between slaves
    while (msg_send_phase < 100000 && global_rank != 0) {
        // Initialize the array of MPI_requests as MPI_REQUEST_NULL, which is necessary for MPI_Waitall to work,
        // because nodes at the border do not have 4 neighbours, so do not execute 4 sends and 4 receives per phase.
        for (i = 0; i < 8; i++) {
            reqs[i] = MPI_REQUEST_NULL;
        }

        // Generate random number to simulate data constituting an event
        data = (rand() % 10);
        // NOTE: Uncomment this segment to check data generated for a specific phase
        // if (msg_send_phase == 3) {
        //     printf("Rank: %d, num: %d\n", cart_rank, data);
        // }

        // If adjacent doesn't exist(i.e. It is a border node), the value would be -2
        // Do a non-blocking receive from valid adjacent nodes
        // The array recv_data has its data represented as {left, right, up, down}
        if (left >= 0) {
            MPI_Irecv(&recv_data[0], 1, MPI_INT, left, left, cart_comm_world, &reqs[req_count]);
            req_count++;
        }
        if (right >= 0) {
            MPI_Irecv(&recv_data[1], 1, MPI_INT, right, right, cart_comm_world, &reqs[req_count]);
            req_count++;
        }
        if (up >= 0) {
            MPI_Irecv(&recv_data[2], 1, MPI_INT, up, up, cart_comm_world, &reqs[req_count]);
            req_count++;
        }
        if (down >= 0) {
            MPI_Irecv(&recv_data[3], 1, MPI_INT, down, down, cart_comm_world, &reqs[req_count]);
            req_count++;
        }

        // Do a non-blocking send to all valid adjacent nodes
        // If adjacent doesn't exist(i.e. It is a border node), the value would be -2
        // Attach cart_rank as message tag to add a layer of redundancy
        if (left >= 0) {
            MPI_Isend(&data, 1, MPI_INT, left, cart_rank, cart_comm_world, &reqs[req_count]);
            req_count++;
        }
        if (right >= 0) {
            MPI_Isend(&data, 1, MPI_INT, right, cart_rank, cart_comm_world, &reqs[req_count]);
            req_count++;
        }
        if (up >= 0) {
            MPI_Isend(&data, 1, MPI_INT, up, cart_rank, cart_comm_world, &reqs[req_count]);
            req_count++;
        }
        if (down >= 0) {
            MPI_Isend(&data, 1, MPI_INT, down, cart_rank, cart_comm_world, &reqs[req_count]);
            req_count++;
        }

        MPI_Waitall(8, reqs, msg_status);  // Hold here until all send and receive operations have cleared

        // Check if there's a valid event
        if (detect_event(recv_data)) {
            MPI_Send(&recv_data, 4, MPI_INT, 0, msg_send_phase, MPI_COMM_WORLD);
            // buf: The 4 adjacent data points
            // message tag: the phase where the event was detected.
            /* Note that this is not a unique mesage tag. But master_node is using MPI_ANY_TAG in its receive,
               rending the tag useless. Therefore, I am using the tag to carrying an additional piece of information to master. */

            //NOTE: Uncomment this segment to debug Event detection
            // printf("------------EVENT-------------\n");
            // printf("Phase: %d \n", msg_send_phase);
            // printf("Cart Rank: %d\n", cart_rank);
            // for (i = 0; i < 4; i++) {
            //     printf("%d ", recv_data[i]);
            // }
            // printf("\n");
        }
        req_count = 0;  // Reset the pointer so the next phase's mpi_request will overwrite the existing
        msg_send_phase++;
        MPI_Barrier(cart_comm_world);   // Added redundancy to ensure that all processes enter the next iteration at the same time
    }
    if (global_rank == 1) { // Use an arbitrary node to send a termination message to master
        termination[1] = msg_send_phase;
        MPI_Send(&termination, 4, MPI_INT, 0, cart_rank, MPI_COMM_WORLD);
    }
    // End of program
    MPI_Finalize();
    return(0);
}

int master_standby_recv(MPI_Comm comm_world) {
    // Master Node's Subroutine
    // Master node will continually post receive operations, receiving from any source, until it receives a termination message.
    // If a slave node detects an event, it will send to master node, where it will log the event into a .txt file
    // Once a termination notice is received, master node will log the time elapsed and other key performance metrics before terminating.
    int i;  // Generic loop variable
    MPI_Status stat;
    int inc_msg[4];
    int node_row, node_col; // Variables to hold the cartesian coords of the node
    int event_count=1;  // Counter for number of events received
    double time_start, time_end;

    time_start = MPI_Wtime();
    // Opens a new file to write into
    FILE *fp;
    fp = fopen("log.txt", "w+");

    while (TRUE) {
        MPI_Recv(&inc_msg, 4, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &stat);
        if (inc_msg[0] != -5) {
            node_row = (stat.MPI_SOURCE -1) / 5;    //Note that this is based on 5 columns
            node_col = (stat.MPI_SOURCE -1) % 5;
            fprintf(fp, "Event: %d, Phase: %d, Reference Node Rank: %d, Cart Coords: (%d,%d), Adjacent Nodes' message(L,R,U,D): ", event_count, stat.MPI_TAG, (stat.MPI_SOURCE - 1), node_row, node_col);
            for (i = 0; i < 4; i++) {
                fprintf(fp, "%d ", inc_msg[i]);
            }
            fprintf(fp, "\n");
            event_count++;
        }
        else {
            time_end = MPI_Wtime();
            printf("Termination message received. Master Node is closing...\n");
            fprintf(fp, "Time taken to create cart grid, exchange messages and logged events: %1.5f\n", (time_end-time_start));
            fprintf(fp, "Total messages(send only) exchanged by nodes: %d\n", (inc_msg[1]*48));
            fprintf(fp, "Total Events detected: %d\n", (event_count -1));
            break;
        }
    }
    fclose(fp);
    return(0);
}


int detect_event(int recv_data[]) {
    // Function just checks that 3 out 4 elements in the array are similar. If yes, return true, else return false
    int j, errors = 0;
    int current;

    if (recv_data[0] == -1) {
        errors++;
        current = recv_data[1];
        //It is not possible, based on topology, for left and right adjacent nodes to be -1(i.e. the reference node doesn't have left and right adjacent nodes)
    }
    else {
        current = recv_data[0];
    }

    for (j=1; j < 4; j++) {
        if (recv_data[j] != current)  {
            errors ++;
        }
        if (errors >= 2) {
            return(0);
        }
    }
    return(1);
}

// NOTE: This detect_event is based on 3 adjacent nodes having the same number as the reference node itself. The question could be intepreted this way
// int detect_event(int data, int recv_data[]) {
//     // Check that at 3 left/right/up/down have identical values with data. If yes, return 1, else return false
//     // All left/right/up/down data were initialized as -1. After send/recv, if they are still -1, it means they are invalid (i.e. the node is a boundary node)
//     // It is impossible to yield a false positive with matching '-1's because the node's own random number generator cannot generate -1.
//     int j, errors = 0;
//     for (j = 0; j< 4; j++) {
//         if (recv_data[j] != data) {
//             errors++;
//         }
//     }
//     if (errors < 2) {
//         return(1);
//     }
//     else {
//         return(0);
//     }
// }
