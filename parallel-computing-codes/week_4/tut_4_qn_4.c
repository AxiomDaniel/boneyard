#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numtasks, rank, rc;
    //Declare all other variables here
    int packsize, position;
    int a;
    double b;
    char packbuf[100];

    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Code begins here */
    while (a >= 0) {
        if (rank == 0) {
            // Make rank 0 process query for input.
            scanf("%d %lf", &a, &b);
            packsize = 0;
            MPI_Pack(&a, 1, MPI_INT, packbuf, 100, &packsize,MPI_COMM_WORLD);
            MPI_Pack(&b, 1, MPI_DOUBLE, packbuf, 100, &packsize,MPI_COMM_WORLD);
        }
        MPI_Bcast(&packsize, 1, MPI_INT, 0, MPI_COMM_WORLD); // Broadcast packsize to all
        MPI_Bcast(packbuf, packsize, MPI_PACKED, 0, MPI_COMM_WORLD); // Broadcast the actual pack to all
        if (rank != 0){
            position = 0;
            MPI_Unpack(packbuf, packsize, &position, &a, 1, MPI_INT, MPI_COMM_WORLD);
            MPI_Unpack(packbuf, packsize, &position, &b, 1, MPI_DOUBLE, MPI_COMM_WORLD);
        }
        printf("Process Rank: %d, received: %d, %lf \n", rank, a, b); // Everyone prints the number they receive
    }
    // End of program
    MPI_Finalize();
    return(0);
}

//MPI_Bcast: Broadcast a message from rank 0 to all other processes
// MPI_Bcast(address_of_buffer, message_count, datatype, root, COMM_WORLD)

// MPI_Pack(buffer_start, number_of_input_data_items, datatype, output_buffer, output_buffer_size(in bytes), output_buffer_address, comm_world)
// Note: the output of this function is the output_buffer
// Packs a datatype into contiguous memory
