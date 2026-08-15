#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

int *C;

void Merge(struct Array *A, struct Array *B){
    int i = 0, j = 0, l = 0, k = A->length+B->length;
    C = (int *)malloc(k*sizeof(int));
    while(i<A->length || j<B->length){
        if(A->a[i]<B->a[j]){
            C[l] = A->a[i];
            i++;l++;
        }
        else if(A->a[i]>B->a[j]){
            C[l] = B->a[j];
            j++;l++;
        }
        else{   //Condition for A->a[i] == B->a[j]
            C[l] = A->a[i]; //Or can use --> C[k] = B->a[j];
            i++;j++;l++;
        }
    }
    if(i != A->length-1){
        C[l] = A->a[i];
    }
    else{
        C[l] = B->a[j];
    }
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
    Merge(&A, &B);
    printf("Merged Array --> ");
    for(int i=0; i<A.length+B.length; i++){
        printf("%d ", C[i]);
    }
    
    return 0;
}