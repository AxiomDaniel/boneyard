#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numprocs, rank, rc;
    //Declare all other variables here
    int dest, source, userInput;
    int tag = 1;
    MPI_Status status;


    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Code begins here */
    dest = rank + 1;    // Destination is the next process
    source = rank - 1;  // Process receives from the previous rank

    while (userInput >= 0) {
        if (rank == 0) {
            scanf("%d", &userInput);
            MPI_Send(&userInput, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
        }
        else {
            MPI_Recv(&userInput, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
            printf("Rank: %d has received message: %d\n", rank, userInput);
            if (rank < numprocs - 1) {  // The last process doesn't need to send
                MPI_Send(&userInput, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
            }
        }
    }

    // End of program
    MPI_Finalize();
    return(0);
}


//MPI_Send(address_of_send_buffer, num_of_elements_to_send, datatype, rank_of_destination, message_tag, comm_world)
// Performs a blocking send

//MPI_Recv(address_of_recv_buffer, num_of_elements_sent, datatype, rank_of_source, message_tag, comm_world, MPI_status)

// MPI_Status: A data structure that is only used for blocking-type receives
// Contains information about:
// 1. MPI source statistics
// 2. MPI tag value
