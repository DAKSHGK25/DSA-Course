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

//METHOD-1
void insert1(struct Array *A, int ele){
    for(int i=0; i<=A->length-1; i++){
        if(A->a[0]>ele){
            for(int i=A->length-1; i>=0; i--){
                A->a[i+1] = A->a[i];
            }
            A->a[0] = ele;
            A->length++;
            break;
        }
        else if(A->a[i]<ele && A->a[i+1]>ele){
            for(int j=A->length-1; j>i; j--){
                A->a[j+1] = A->a[j];
            }
            A->a[i+1] = ele;
            A->length++;
            break;
        }
    }
}

//METHOD-2
void insert2(struct Array *A, int ele){
    for(int i=A->length-1; i>=0; i--){
        if(A->a[i]>ele){
            A->a[i+1] = A->a[i];
        }
        else{
            A->a[i+1] = ele;
            A->length++;
            break;
        }
    }
    A->a[0] = ele;
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
    int ele;
    printf("Enter the element to be Inserted in the SORTED Array: ");
    scanf("%d", &ele);
    insert1(&A, ele);
    printf("Sorted Array --> ");
    display(A);
    return 0;
}