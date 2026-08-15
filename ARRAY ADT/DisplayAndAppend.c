#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *a;
    int size;
    int length;
};

void Display(struct Array A){
    for(int i=0; i<A.length; i++){
        printf("%d ", A.a[i]);
    }
}

void Append(struct Array *A, int x){
    if(A->length < A->size){
        A->a[A->length] = x;
        A->length++;
    }
    else{
        printf("Enter a valid INDEX!\n");
    }
}

int main(){
    struct Array A;
    printf("Enter the size of an Array: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size*sizeof(int));
    int n;
    printf("Enter the number of Array elements: ");
    scanf("%d", &n);
    A.length = n;
    printf("Enter the Array elements: ");
    for (int i = 0; i < A.length; i++)
    {
        scanf("%d", &A.a[i]);
    }
    printf("Array --> \n");
    Display(A);
    printf("\n");
    int ele;
    printf("Enter an element to APPEND to the Array: ");
    scanf("%d", &ele);
    Append(&A, ele);
    printf("Array --> \n");
    Display(A);
    return 0;
}