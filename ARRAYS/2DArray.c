#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. 2D Array by initialisation --> Completely stored inside the STACK
    // data_type array_name[rows][cols] = {sub-arrays, where each sub-array is a row}
    int A[2][4] = {{1,2,3,4}, {5,6,7,8}};
    printf("Array A\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // 2. Using integer pointer array. Where each integer pointer is a row pointing to the row elements.
    // The integer pointers are stored in STACK but the elements are stored in HEAP.
    int *B[2];
    B[0] = (int *)malloc(2*sizeof(int));
    B[1] = (int *)malloc(2*sizeof(int));
    B[0][0] = 1; B[0][1] = 2; B[1][0] = 3; B[1][1] = 4;
    printf("Array B\n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // 3. Using double pointers --> Completely stored in HEAP
    int **C;
    C = (int **)malloc(2*sizeof(int *));
    C[0] = (int *)malloc(2*sizeof(int));
    C[1] = (int *)malloc(2*sizeof(int));
    C[0][0] = 10; C[0][1] = 20; C[1][0] = 30; C[1][1] = 40;
    printf("Array C\n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}