#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

void display(struct Array *A){
    for(int i=0; i<A->length; i++){
        printf("%d ", A->a[i]);
    }
}
struct Array *C;
void intersection(struct Array *A, struct Array *B){
    C = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    while(i<A->length || j<B->length){
        if(A->a[i]>B->a[j]){
            j++;
        }
        else if(A->a[i]<B->a[j]){
            i++;
        }
        else{
            C->a[k] = A->a[i];  //Or can also use C->a[k] = B->a[j];
            i++;j++;k++;
        }
    }
    C->length = k;
}

int main(){
    struct Array A;
    printf("Enter the size of Array1: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size*sizeof(int));
    printf("Enter the number of Array1 elements: ");
    scanf("%d", &A.length);
    printf("Enter the Array1 elements: ");
    for(int i=0; i<A.length; i++){
        scanf("%d", &A.a[i]);
    }
    struct Array B;
    printf("Enter the size of Array2: ");
    scanf("%d", &B.size);
    B.a = (int *)malloc(B.size*sizeof(int));
    printf("Enter the number of Array2 elements: ");
    scanf("%d", &B.length);
    printf("Enter the Array2 elements: ");
    for(int i=0; i<B.length; i++){
        scanf("%d", &B.a[i]);
    }
    printf("Array 1 --> ");
    display(&A);
    printf("\nArray 2 --> ");
    display(&B);
    intersection(&A, &B);
    printf("\nIntersection Array --> ");
    display(C);
    return 0;
}