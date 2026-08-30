// Lower Bound -->> smallest index such that arr[index]>=n ; n - any given number

#include <stdio.h>
#include <stdlib.h>

int lowerBound(int *arr, int len, int n){
    int l = 0, h = len-1, mid, ans = len;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] >= n){
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
    int arr[] = {1,2,3,3,5,8,8,10,10,11}, len = sizeof(arr)/sizeof(arr[0]);
    printf("\n-->> Lower Bound: %d\n\n", lowerBound(arr, len, 0));
    return 0;
}