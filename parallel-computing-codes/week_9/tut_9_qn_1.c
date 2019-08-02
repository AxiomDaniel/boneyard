#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library
#include <string.h>

int main(int argc, char *argv[]) {
    int numprocs, rank, rc;
    //Declare all other variables here
    MPI_Comm new_comm;

    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Code begins here */
    MPI_Comm_split(MPI_COMM_WORLD, rank == 0, 0, &new_comm);
    if (rank == 0) {
        master_io(MPI_COMM_WORLD);
    }
    else {
        slave_io(MPI_COMM_WORLD, new_comm);
    }

    // End of program
    MPI_Finalize();
    return(0);
}

// Function for master
int master_io(MPI_Comm master_comm) {
    int i,j, size;
    char buf[256];
    MPI_Status status;

    MPI_Comm_size(master_comm, &size);
    for (j = 1; j <= 2; j++) {  //j represents the number of messages each process will send to the master
        for (i = 1; i < size; i++) {
            // MPI_Recv(buf, 256, MPI_CHAR, MPI_ANY_SOURCE, 0, master_comm, status);
            MPI_Recv(buf, 256, MPI_CHAR, i, 0, master_comm, &status);
            fputs(buf, stdout);     // This is an archaic way of printf...
        }
    }
}

// Function for slave
int slave_io(MPI_Comm master_comm, MPI_Comm comm) {
    char buf[256];  //Creates a character array of size 256
    int new_rank;

    MPI_Comm_rank(comm, &new_rank); // Now he knows his rank in the newly created communicator
    sprintf(buf, "Hello from slaves %d\n", new_rank);   //sprintf just basically writes whatever into the buf variable. Thats all
    MPI_Send(buf, strlen(buf) + 1, MPI_CHAR, 0, 0, master_comm); //Okay, its sending it on the MPI_COMM_WORLD channel addressed to rank 0. seriously strlen can just be replaced with 256
    sprintf(buf, "Goodbye from slaves %d\n", new_rank);   //sprintf just basically writes whatever into the buf variable. Thats all
    MPI_Send(buf, strlen(buf) + 1, MPI_CHAR, 0, 0, master_comm); //Same bs

    return(0);
}

// MPI_Comm_split(MPI_COMM_WORLD, int color, int key, new_comm_world)
// color refers to an integer that will form the statement to group the processes.
// One good example of this is we have processes rank 0 to 15. We execute color = rank / 4
// This will result in 4 groups of colours. Group 0, 1, 2 and 3. Why? process 0 to 3 when divided by 4 yields 0, process 4 to 7 yields 1, so on so forth.
// Over in this example, we're using rank == 0 which will return true false, 1 0. We're only hoping to split into 2 groups, rank 0 is group 1, the others belong to group 2.
