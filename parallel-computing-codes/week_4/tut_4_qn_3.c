#include <stdio.h>  // Import standard input/output library
#include <mpi.h>    // Import MPI library

int main(int argc, char *argv[]) {
    int numtasks, rank, rc;
    //Declare all other variables here
    //Create new datatype to handle integer and double
    struct {
        int a;
        double b;
    } userInput;
    MPI_Datatype myStruct;  // Declare a MPI_Datatype called myStruct
    int blocklens[2];   // Declare an array of intergers named blocklens. The array size is 2. blocklens refers to number of elements in each block
    MPI_Aint indices[2]; //Delare an array of MPI_Aint named indices. The array size is 2. MPI_Aint is a C type that holds any valid address
    MPI_Datatype old_types[2]; // Declare an array of MPI_Datatype named old_types. The array size is 2.

    //Standard MPI initialization steps
    rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        printf("Error starting MPI program. Aborting.\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
    }
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Code begins here */

    // blocklens refers to the number of elements in each block. I'm now declaring that they will have one element in each block
    blocklens[0] = 1;
    blocklens[1] = 1;

    // Declare the MPI_Datatype inside array 'old_types'
    old_types[0] = MPI_INT;
    old_types[1] = MPI_DOUBLE;

    // MPI_Address puts the address of the location into the indices array
    // The indices array holds the address of userInput.a and userInput.b
    // Almost like doing indices[0] = &userInput.a, but for each process, which has a different memory spaces
    MPI_Get_address(&userInput.a, &indices[0]);
    MPI_Get_address(&userInput.b, &indices[1]);
    printf("userInput.a = %d, address = %p\n", userInput.a, &userInput.a);
    printf("indices[0] = %p, address = %p\n", indices[0], &indices[0]);
    // %p is for printing pointers.

    //IDK what this does. It says "Make Relative" dafuq?
    // Apparently indices contains the number of bytes displacements?
    indices[1] = indices[1] - indices[0];
    indices[0] = 0;
    // Create the custom datatype
    MPI_Type_create_struct(2, blocklens,indices,old_types,&myStruct);
    MPI_Type_commit(&myStruct);

    // Input/Broadcast segment
    while (userInput.a >= 0) {
        if (rank == 0) {
            // Make rank 0 process query for input.
            scanf("%d %lf", &userInput.a , &userInput.b);
        }
        MPI_Bcast(&userInput, 1, myStruct, 0, MPI_COMM_WORLD);   //Rank 0 broadcasts to all
        printf("Process Rank: %d, received: %d and %lf \n", rank, userInput.a, userInput.b); // Everyone prints the number they receive
    }

    // Clean the custom MPI_Datatype
    MPI_Type_free( &myStruct);

    // End of program
    MPI_Finalize();
    return(0);
}

// MPI_Address(location_in_caller_memory, address_of_location)
// Gets the address of a location in memory.

// MPI_Type_create_struct(number_of_blocks, number_of_elements_in_each_block, number_of_bytes_in_each_block, array_of_types, address_of_created_datatype)
// Creates a struct datatype in MPI
