#include <stdio.h>

void main() {
    int AValue, *BValue;

    printf("Initial declared address of AValue=%p AValue=%d\n", &AValue, AValue );
    printf("I'm going to declare AValue to be 101\n");
    AValue = 101;
    printf("Address of AValue %p AValue=%d\n", &AValue, AValue);
    printf("Same address, different value.\n\n");

    printf("I'm going to save the address of AValue into BValue.\n");
    BValue = &AValue;
    printf("BValue = %p\n", BValue );
    printf("as expected...\n");
    printf("I'm going to use the derefence operator on BValue, which is the address of AValue\n");
    printf("I should get back the value of 101. Here goes...\n");
    printf("Dereference of BValue= %d\n", *BValue );
    printf("Voila!\n");
}


// Reference Operator (&) is used to find the address of a variable
// Dereference operator (*) is used to find the value stored at the address of the variable
