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

int Delete(struct Array *A, int index){
    int x = 0;
    if(index>=0 && index<A->length){
        x = A->a[index];
        for(int i=index; i<(A->length)-1; i++){
            A->a[i]=A->a[i+1];
        }
        A->length--;}
    else{
        printf("Invalid Index for DELETION!\n");
    }
    return x;
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
    int index;
    printf("Enter position (index) at which DELETION is to be done: ");
    scanf("%d", &index);
    printf("Element DELETED from Array is: %d\n", Delete(&A, index));
    printf("Array --> \n");
    Display(A);
    printf("\n");
    return 0;
}