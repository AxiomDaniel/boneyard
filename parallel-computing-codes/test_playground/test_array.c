#include <stdio.h>

int main() {
    int array[10], c;

    for (c = 0; c < 5; c++) {
        scanf("%d", &array[c]);
    }


    printf("array:\n");
    for (c=0; c<10; c++) {
        printf("%d\n", array[c] );
    }
}
