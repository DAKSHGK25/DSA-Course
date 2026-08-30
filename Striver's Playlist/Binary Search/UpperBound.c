// Lower Bound -->> smallest index such that arr[index]>=n ; n - any given number

#include <stdio.h>
#include <stdlib.h>

int upperBound(int *arr, int len, int n){
    int l = 0, h = len-1, mid, ans = len;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] > n){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {2,3,6,7,8,8,11,11,11,12}, len = sizeof(arr)/sizeof(arr[0]);
    printf("\n-->> Upper Bound: %d\n\n", upperBound(arr, len, 12));
    return 0;
}