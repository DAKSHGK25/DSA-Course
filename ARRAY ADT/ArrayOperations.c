#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

void Display(struct Array A){
    for(int i=0; i<A.length; i++){
        printf("%d ", A.a[i]);
    }
}

void get(struct Array A, int index){
    if(index>=0 && index<A.length){
        printf("The element at INDEX %d is: %d\n", index, A.a[index]);
    }
    else{
        printf("Invalid INDEX!");
    }
}

void set(struct Array A, int index, int ele){
    if(index>=0 && index<A.length){
        A.a[index] = ele;
        printf("Element 'SET' successfully!\n");
    }
    else{
        printf("Invalid INDEX!");
    }
}

int maximum(struct Array A){
    int max = A.a[0];
    for(int i=1; i<A.length; i++){
        if (max < A.a[i]){
            max = A.a[i];
        }
    }
    return max;
}

int minimum(struct Array A){
    int min = A.a[0];
    for(int i=1; i<A.length; i++){
        if (min > A.a[i]){
            min = A.a[i];
        }
    }
    return min;
}

//ITERATIVE FUNCTION
int sum(struct Array A){
    int arr_sum = 0;
    for (int i = 0; i < A.length; i++)
    {
        arr_sum += A.a[i];
    }
    return arr_sum;
}

//RECURSIVE FUNCTION
// int sum(int *arr, int n){
//     if (n == 0){return arr[n];}
//     else{
//         return arr[n] + sum(arr, n-1);
//     }
// }

float avg(struct Array A){
    return (float)sum(A)/A.length;
}

int main(){
    struct Array A;
    printf("Enter the size of Array: ");
    scanf("%d", &A.size);
    A.a = (int *)malloc(A.size*sizeof(int));
    int n;
    printf("Enter the number of Array elements: ");
    scanf("%d", &n);
    A.length = n;
    printf("Enter the Array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &A.a[i]);
    }
    int index, ele;

    //<-- GET OPERATION -->
    // printf("Enter the index of the 'GET' element: ");
    // scanf("%d", &index);
    // get(A, index);

    //<-- SET OPERATION -->
    // printf("Enter the index of the element to be 'SET': ");
    // scanf("%d", &index);
    // printf("Enter the element with which it has to be 'SET': ");
    // scanf("%d", &ele);
    // set(A, index, ele);
    // printf("Array after 'SET' --> ");
    // Display(A);

    //<-- MAX OPERATION O(n) -->
    // printf("Maximum element of Array is: %d\n", maximum(A));

    //<-- MIN OPERATION O(n) -->
    // printf("Minimum element of Array is: %d\n", minimum(A));

    //<-- SUM OPERATION -->
    // printf("Sum of elements of Array is: %d\n", sum(A.a, A.length-1));

    //<-- AVERAGE OPERATION -->
    printf("Average of elements of Array is: %.2f\n", avg(A));
    return 0;
}