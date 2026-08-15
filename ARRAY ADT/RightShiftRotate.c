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

void rightShift(struct Array *A){
    for(int i=A->length-1; i>=0; i--){
        A->a[i] = A->a[i-1];
    }
    A->a[0] = 0;
}

void rightRotate(struct Array *A, int j){
    for(int k=0; k<j; k++){
        int e = A->a[A->length-1];
        for(int i=A->length-1; i>=0; i--){
            A->a[i] = A->a[i-1];
        }
        A->a[0] = e;
    }
}

int main(){
    struct Array A;
    printf("Enter the size of Array: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size);
    printf("Enter the number of Array elements: ");
    scanf("%d", &A.length);
    printf("Enter the Array elements: ");
    for(int i=0; i<A.length; i++){
        scanf("%d", &A.a[i]);
    }
    printf("Array after Right Shift --> ");
    rightShift(&A);
    display(A);
    int j;
    printf("\nEnter the number of indices for Rotation: ");
    scanf("%d", &j);
    printf("Array after Right Rotation by %d index --> ", j);
    rightRotate(&A, j);
    display(A);
    return 0;
}