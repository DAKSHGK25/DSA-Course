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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void NegOnLeft(struct Array *A){
    int i=0, j=A->length-1;
    while(i<j){
        if(A->a[i]<0){i++;}
        if(A->a[j]>=0){j--;}
        if(A->a[i]>0){
            if(A->a[j]>=0){j--;}
            else{
                swap(&A->a[i], &A->a[j]);
                j--;i++;
            }
        }
        if(A->a[j]<0){
            if(A->a[i]<=0){i++;}
            else{
                swap(&A->a[i], &A->a[j]);
                i++;j--;
            }
        }
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
    printf("Array --> ");
    display(A);
    NegOnLeft(&A);
    printf("\nRearranged Array --> ");
    display(A);
    return 0;
}