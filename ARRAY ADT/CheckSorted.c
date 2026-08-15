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

void check(struct Array A){
    for(int i=0; i<A.length-1; i++){
        if(A.a[i] > A.a[i+1]){
            printf("\nIt's an UNSORTED Array!");
            return;
        }
    }
    printf("\nIt's a SORTED Array!");
    return;
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
    check(A);
    return 0;
}