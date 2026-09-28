#include <stdio.h>
#include <stdlib.h>

int Minimum(int *arr, int len){
    int l = 0, h = len-1, mid, ans = arr[0];
    while(l<=h){
        mid = l + (h-l)/2;
        if(arr[l] <= arr[mid]){
            if(ans > arr[l]){ans = arr[l];}
            l = mid+1;
        }
        else{
            if(ans > arr[mid]){ans = arr[mid];}
            h = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2}, len = sizeof(arr)/sizeof(arr[0]);
    int res = Minimum(arr, len);
    printf("\n-->> Minimum element is: %d\n\n", res);
    return 0;
}