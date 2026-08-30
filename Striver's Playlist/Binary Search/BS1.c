#include <stdio.h>
#include <stdlib.h>

// Iterative Version
int BinarySearch(int *arr, int len, int x){
    int l = 0, h = len-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        if(arr[mid] == x){return mid;}
        else if(arr[mid] > x){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

// Recursive Version
int BinarySearchRec(int *arr, int len, int l, int h, int x){
    if(l>h){return -1;}
    int mid = (l+h)/2;
    if(arr[mid] == x){return mid;}
    else if(arr[mid] > x){
        return BinarySearchRec(arr, len, l, mid-1, x);
    }
    return BinarySearchRec(arr, len, mid+1, h, x);
}

int main(){
    int arr[] = {3,4,6,7,9,12,16,17};
    int target = 21, len = sizeof(arr)/sizeof(arr[0]);
    // int index = BinarySearch(arr, len, target);
    int index = BinarySearchRec(arr, len, 0, len-1, target);
    if(index != -1){printf("\n-->> Key %d is found at index %d!\n\n", target, index);}
    else{printf("\n-->> Key %d is not found!\n\n", target);}
    return 0;
}