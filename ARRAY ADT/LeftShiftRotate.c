#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

void display(struct Array A){
    for(int i=0; i<A.length; i++){
        printf("%d ", A.a[i]);
    }
}

void leftShift(struct Array *A){
    for(int i=0; i<A->length; i++){
        A->a[i] = A->a[i+1];
    }
    A->a[A->length-1] = 0;
}

void leftRotate(struct Array *A, int j){
    for(int k=0; k<j; k++){
        int e = A->a[0];
        for(int i=0; i<A->length; i++){
            A->a[i] = A->a[i+1];
        }
        A->a[A->length-1] = e;
    }
}

int main(){
    struct Array A;
    printf("Enter the size of Array: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size);
    printf(("Enter the number of Array elements: "));
    scanf("%d", &A.length);
    printf("Enter the Array elements: ");
    for(int i=0; i<A.length; i++){
        scanf("%d", &A.a[i]);
    }
    printf("Array after Left Shift --> ");
    leftShift(&A);
    display(A);
    int j;
    printf("\nEnter the number of indices for Rotation: ");
    scanf("%d", &j);
    printf("Array after Left Rotation by %d index --> ", j);
    leftRotate(&A, j);
    display(A);
    return 0;
}