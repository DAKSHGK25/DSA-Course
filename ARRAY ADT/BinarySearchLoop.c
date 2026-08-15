#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

int BinarySearch(struct Array A, int l, int h, int ele){
    while(l <= h){
        int mid = (l+h)/2;
        if(ele == A.a[mid]){
            return mid;
        }
        else if (ele > A.a[mid]){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
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
    printf("Enter the Array elements (in Ascending Order): ");
    for(int i=0; i<n; i++){
        scanf("%d", &A.a[i]);
    }
    int ele;
    printf("Enter the Element to be SEARCHED: ");
    scanf("%d", &ele);
    int l = 0, h = A.length-1;
    int pos = BinarySearch(A, l, h, ele);
    if(pos == -1){
        printf("Element NOT FOUND!");
    }
    else{
        printf("Element FOUND at index %d!", pos);
    }
    return 0;
}