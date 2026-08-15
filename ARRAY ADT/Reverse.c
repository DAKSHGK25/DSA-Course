#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

//Reversing using an AUXILLARY ARRAY
void rev1(struct Array *A){
    int *B = (int *)malloc(A->length*sizeof(int));
    for(int i=0; i<A->length; i++){
        B[A->length-i-1] = A->a[i];
    }
    for(int i=0; i<A->length; i++){
        A->a[i] = B[i];
    }
}

//Reversing WITHOUT using an AUXILLARY ARRAY --> INPLACE REVERSING
void rev2(struct Array *A){
    for(int i=0; i<A->length/2; i++){
        int first = A->a[i];
        int second = A->a[A->length-i-1];
        //Reversing VARIABLES 'first' and 'second'
        int temp = first;
        first = second;
        second = temp;
        //Now reverse the 'ACTUAL' array elements
        A->a[i] = first;
        A->a[A->length-i-1] = second;
    }
}

int main(){
    struct Array A;
    printf("Enter the size of an Array: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size*sizeof(int));
    printf("Enter the number of Array elements: ");
    scanf("%d", &A.length);
    printf("Enter the Array elements: ");
    for(int i=0; i<A.length; i++){
        scanf("%d", &A.a[i]);
    }
    rev1(&A);
    printf("Reversed Array -->\n");
    for(int i=0; i<A.length; i++){
        printf("%d ", A.a[i]);
    }
    return 0;
}