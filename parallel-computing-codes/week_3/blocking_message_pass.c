#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    // Declare your variables
    int numtasks, rank, dest, source, rc, count, tag = 1;
    char inmsg, outmsg='x';
    MPI_Status Stat;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("Rank 0 commencing\n");
        dest = 1;
        source = 1;
        rc = MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);     // Rank 0 sends to rank 1.
        rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat); // Rank 0 receiving from rank 1
        printf("Rank 0 finished running\n");
    }
    else if (rank == 1) {
        printf("Rank 1 commencing\n");
        dest = 0;
        source = 0;
        rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat); // Rank 1 receiving from rank 0
        rc = MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);     // Rank 1 sending to rank 0
        printf("Rank 1 finished running\n");
    }

    rc = MPI_Get_count(&Stat, MPI_CHAR, &count);
    printf("Rank %d: Received %d char(s) from rank %d with tag %d \n", rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);

    MPI_Finalize();
}

// Key is that this is a blocking message passing routine.
// Also: Blocking == Synchronous. Remember
// Step through:
// 1. line 17 executes: Rank 0 sends to rank 1. Rank 0 blocks itself.
// 1.1 Simultaneously, line 23 also executes, rank 1 receiving from rank 0. Rank 1 blocks itself for a very brief period before it receives. Rank 0 can unblock now.
// 2. line 18 executes: Rank 0 receiving from rank 1. Rank 0 is suspended and awaiting right now.
// 2.1 Line 24 executes: Rank 1 sends to rank 0. Since rank 0 was already receiving. Rank 0 and 1 unblocks once the message resolves.

// The takeaway in this exercise is to show that the send and receive statements for both ranks are different positioned. If they were in the same order, a deadlock might ensue.


// MPI_Status: A data structure that is only used for blocking-type receives
// Contains information about:
// 1. MPI source statistics
// 2. MPI tag value
