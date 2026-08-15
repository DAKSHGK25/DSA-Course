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

void Insert(struct Array *A, int index, int ele){
    if(index>=0 && index<=A->length){
        for(int i=(A->length)-1; i>=index; i--){
            A->a[i+1] = A->a[i];
        }
        A->a[index] = ele;
        A->length++;}
    else{
        printf("Invalid Index for INSERTING!\n");
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
    int index, ele;
    printf("Enter position (index) at which INSERTION is to be done: ");
    scanf("%d", &index);
    printf("Enter element which is to be INSERTED: ");
    scanf("%d", &ele);
    Insert(&A, index, ele);
    printf("Array --> \n");
    Display(A);
    printf("\n");
    return 0;
}