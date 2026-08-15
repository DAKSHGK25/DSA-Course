#include <stdio.h>
#include <stdlib.h>

struct Array {
    int a[20];
    int size;
    int length;
};

void Display(struct Array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.a[i]);
    }
}

int main(){
    struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};
    int n;
    // printf("Enter size of an array: ");
    // scanf("%d", &arr.size);
    // arr.a = (int *)malloc(arr.size*sizeof(int));    //Array is in HEAP;
    // arr.length = 0;
    // printf("Enter number of Array elements: ");
    // scanf("%d", &n);
    // printf("Enter array elements: ");
    // for(int i=0; i<n; i++){
    //     scanf("%d", &arr.a[i]);
    // }
    // arr.length = n;
    Display(arr);
    return 0;
}