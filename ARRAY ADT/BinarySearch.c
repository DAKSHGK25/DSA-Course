#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *a;
    int size;
    int length;
};

int BinSearch(struct Array A, int ele, int l, int h){
    if(l > h){
        return -1;
    }
    else{
        int mid = (l+h)/2;
        if(ele == A.a[mid]){
            return mid;
        }
        else if(ele > A.a[mid]){
            //l = mid+1;
            return BinSearch(A, ele, mid+1, h);
        }
        else{
            //h = mid-1;
            return BinSearch(A, ele, l, mid-1);
        }
    }
    //BinSearch(A, ele, l, h);
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
    int pos = BinSearch(A, ele, l, h);
    if(pos == -1){
        printf("Element NOT FOUND!");
    }
    else{
        printf("Element FOUND at index %d!", pos);
    }
    return 0;
}