#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numtasks, rank, rc;
    //Declare all other variables here
    int userInput;

    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Code begins here */
    while (userInput >= 0) {
        if (rank == 0) {
            // Make rank 0 process query for input.
            scanf("%d", &userInput);
        }
        MPI_Bcast(&userInput, 1, MPI_INT, 0, MPI_COMM_WORLD);   //Rank 0 broadcasts to all
        printf("here\n");
        printf("Process Rank: %d, received: %d \n", rank, userInput); // Everyone prints the number they receive
    }
    // End of program
    MPI_Finalize();
    return(0);
}


//MPI_Bcast: Broaccst a message from rank 0 to all other processes
// MPI_Bcast(address_of_buffer, message_count, datatype, root, COMM_WORLD)
