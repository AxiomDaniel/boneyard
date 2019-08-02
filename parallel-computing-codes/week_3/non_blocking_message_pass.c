#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numtasks, rank, next, prev, buf[2], tag1=1, tag2=2;
    MPI_Request reqs[4];
    MPI_Status stats[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    prev = rank - 1;
    next = rank + 1;

    if (rank == 0) {
        prev = numtasks - 1;
        // We're trying to make a ring. So first process needs to link to the last process
    }
    if (rank == (numtasks - 1)) {
        next = 0;
        // And of course, last process needs to link with the first.
    }

    MPI_Irecv(&buf[0], 1, MPI_INT, prev, tag1, MPI_COMM_WORLD, &reqs[0]);   // Set up a receive from the previous rank, and store it in buf[0]. Display mailbox to receive tag 1
    MPI_Irecv(&buf[1], 1, MPI_INT, next, tag2, MPI_COMM_WORLD, &reqs[1]);   // Set up a receive from the next rank, and store it in buf[1]. Display mailbox to receive tag 2
    MPI_Isend(&rank, 1, MPI_INT, prev, tag2, MPI_COMM_WORLD, &reqs[2]);     // Send its rank number to the previous rank. Tag mail as tag 2(i.e. it can only go to a tag 2 mailbox)
    MPI_Isend(&rank, 1, MPI_INT, next, tag1, MPI_COMM_WORLD, &reqs[3]);     // Send its rank number to the next rank. Tag mail as tag 1(i.e. it can only go to a tag 1 mailbox)
    // buf[0] is going to hold the previous rank's number(current rank-1). buf[1] is going to hold the next rank's number(current rank+1)

    MPI_Waitall(4, reqs, stats);    //Make sure everyone is cleared before starting the print statements
    printf("I am rank %d buf[0]=%d, buf[1]=%d\n", rank, buf[0], buf[1]);
    MPI_Finalize();
}


// MPI_Irecv(buffer, buffer count, MPI_Datatype, source, tag, MPI_COMM_WORLD, MPI_Request)
// Begins a non-blocking receive.

//MPI_Isend(buffer, buffer count, MPI_Datatype, destination, tag, MPI_COMM_WORLD, MPI_Request)
// Begins a non-blocking send.


//MPI_Waitall(list_length, array_of_MPI_requests, array_of_statuses)
// Waits for all given MPI Requests to complete
// Suppose you allow a series of non-blocking message passes, and it's havoc, like traffic going everywhere. Now you wish to start another segment of code, or maybe change a variable's value that was previously required. So you use a wait all to block your code, make sure every process is back on the same page and at the same starting line again before continuing.

// MPI_Request: This is a number required for non-blocking operations. We know for non-blocking operations, things just continue to execute with no care in the world.
// Think of MPI_Request as a magic box, it will know whether the message is cleared or not; whether the buffer is safe for reuse. So even if each thread is going about their own business. This request is still keeping tabs of this message operation.
// By using the appropriate functions to query MPI_Request (WAIT type routines), the programmer can determine whethe the non-blocking operation is completed. And so whether or not we can reuse the system buffer safely.

// Tag: A non-negative integer used to uniquely identify a message. Every message has a tag (identifier). More advanced applications of this is that we can use the tag number to filter messages. But the basic is a send has a tag, and a receive should take that tag. Sort of like specific an address to send a mail. The sender must have it, and the receiver should display it to ensure it enters the right place. There's also the option of MPI_ANY_TAG which means I don't care what I receive, just give me anything here.
