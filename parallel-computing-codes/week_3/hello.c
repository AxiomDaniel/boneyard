#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numprocs, rank, namelen;    // Declare integer variables: number of processors, rank, length of name
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);   // Outputs the number of processors in the comm group to numprocs variable. Python equiv: numprocs = MPI_Comm_size(MPI_COMM_WORLD)
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);       // Same thing, but this time for rank, each process has its own rank
    MPI_Get_processor_name(processor_name, &namelen);   //Same thing, but this function outputs two variables, the processor name and its name's length.

    printf("Process %d on %s out of %d\n", rank, processor_name, numprocs);

    MPI_Finalize();
}

// Key understanding to make here is that for each process, think of it as its own computer running this exact same segment of code, and each of them has its own variable for rank and numprocs.
