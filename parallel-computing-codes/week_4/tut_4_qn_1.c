#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numprocs, rank, rc;
    //Declare all other variables here

    //Standard MPI initialization steps.
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    // Every process knows how many processes in this COMM_WORLD, at the 'numprocs' variable
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    // Each process has its rank stored in the 'rank' variable
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Code begins here
    printf("Hello world from process %d of %d\n", rank, numprocs);


    // End of program
    MPI_Finalize();
    return(0);
}
