#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

void Search(struct Array A, int ele){
    for(int i=0; i<A.length; i++){
        if(A.a[i]==ele){
            printf("Element %d is FOUND in the Array at index %d!\n", ele, i);
            return;
        }
    }
    printf("Element %d is NOT FOUND in the Array!\n", ele);
    return;
}

int main(){
    struct Array A;
    printf("Enter the size of Array: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size*sizeof(int));
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    A.length = n;
    printf("Enter the Array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &A.a[i]);
    }
    int ele;
    printf("Enter an Element to SEARCH in the Array: ");
    scanf("%d", &ele);
    Search(A, ele);
    return 0;
}