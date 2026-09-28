#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int NoOfRotations(int *arr, int len){
    int l = 0, h = len-1, mid, ans = INT_MAX, index = -1;
    while(l<=h){
        mid = l + (h-l)/2;
        
        // if(arr[l] <= arr[h]){
        //     index = l; break;
        // }

        if(arr[l] == arr[mid] && arr[mid] == arr[h]){
            if(ans > arr[mid]){
                ans = arr[l]; index = l; l++; h--; continue;
            }
        }

        if(arr[l] <= arr[mid]){
            if(ans > arr[l]){
                ans = arr[l]; index = l;
            }
            l = mid+1;
        }
        else{
            if(arr[mid] <= ans){
                ans = arr[mid]; index = mid;
            }
            h = mid-1;
        }
    }
    return index;
}

int main(){
    int arr[] = {3,1,2,3,3,3,3/*3,3,4,4,4,5,1,2*/}, len = sizeof(arr)/sizeof(arr[0]);
    int index = NoOfRotations(arr, len);
    printf("\n-->> No. of Rotations: %d\n\n", index);
    return 0;
}