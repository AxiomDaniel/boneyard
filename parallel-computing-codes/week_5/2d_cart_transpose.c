#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numprocs, rank, rc;
    //Declare all other variables here
    int userInput;
    int tag = 1;
    MPI_Status status;
    int periodic[] = {0,0};
    int up, down, left, right;    // For each process, this will hold its 4 directions
    int ring_rank, ring_size;   // In the new communication handle, the rank and the size.
    int dims[2];
    int i=0;
    MPI_Comm ring_comm; //The new communication handle

    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Code begins here */

    // Update dimensions properly
    dims[0] = 4;    //4 rows
    dims[1] = 5;    //5 cols
    // for (i = 0; i < 2; i++) {
    //     printf("%d ", dims[i]);
    // }

    // Create cartesian grid of processes
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periodic, 1, &ring_comm);
    // 1 dimension, the number of processes in that dimension is the size.
    MPI_Cart_shift(ring_comm, 1, 1, &left, &right);
    MPI_Cart_shift(ring_comm, 0, 1, &up, &down);
    MPI_Comm_rank(ring_comm, &ring_rank);
    MPI_Comm_size(ring_comm, &ring_size);


    // Ring communications
    // while (userInput >= 0) {
    //     if (rank == 0) {
    //         scanf("%d", &userInput);
    //         MPI_Send(&userInput, 1, MPI_INT, right, tag, ring_comm);
    //     }
    //     else {
    //         MPI_Recv(&userInput, 1, MPI_INT, left, tag, ring_comm, &status);
    //         printf("Rank: %d has received message: %d\n", ring_rank, userInput);
    //         if (rank < numprocs - 1) {  // The last process doesn't need to send
    //             MPI_Send(&userInput, 1, MPI_INT, right, tag, ring_comm);
    //         }
    //     }
    // }

    if (ring_rank == 14) {
        scanf("%d", &userInput);
        printf("Rank: %d, Ring_rank: %d\n", rank, ring_rank);
        printf("Left Ring_rank: %d\n", left);
        printf("Right Ring_rank: %d\n", right);
        printf("Up Ring_rank: %d\n", up);
        printf("Down Ring_rank: %d\n", down);
        MPI_Send(&userInput, 1, MPI_INT, left, tag, ring_comm);
        printf("Rank: %d, Ring_rank: %d I've sent\n", rank, ring_rank);
        // MPI_Send(&userInput, 1, MPI_INT, down, tag, ring_comm);
    }
    else {
        MPI_Recv(&userInput, 1, MPI_INT, 14, tag, ring_comm, &status);
        printf("Rank: %d, Ring_rank: %d has received message: %d\n", rank, ring_rank, userInput);
    }



    // End of program
    MPI_Finalize();
    return(0);
}

// MPI_Cart_create(old_comm_world, num_of_dimensions, array_of_dimensions, periodic_grid_array_int, allow_reorder_ranks_int, new_Comm_World)
// Makes a new communicator to which topology information has been attached
// num_of_dimensions refers to 1D,2D,3D. For assignment, its a 2D grid. so 2.
// array_of_dimensions is an array of integers. for a 2 dimensional grid, it should look like {nrow, ncol}.
// If the grid wraps around, it is a periodic_grid. It is an array of integers. Specify 1 for true, and 0 for false.


// MPI_Cart_shift(comm_world, coordinate_dimension_of_shift(int), displacement(int), source_rank, dest_rank)
// Returns the shifted source and destination ranks, given a shift direction and amount
// I think coordinate_dimension_of_shift refers to the dimension that is shifting to.
// The outputs for this function is the source_rank, and the dest_rank



//MPI_Send(address_of_send_buffer, num_of_elements_to_send, datatype, rank_of_destination, message_tag, comm_world)
// Performs a blocking send

//MPI_Recv(address_of_recv_buffer, num_of_elements_sent, datatype, rank_of_source, message_tag, comm_world, MPI_status)

// MPI_Status: A data structure that is only used for blocking-type receives
// Contains information about:
// 1. MPI source statistics
// 2. MPI tag value
