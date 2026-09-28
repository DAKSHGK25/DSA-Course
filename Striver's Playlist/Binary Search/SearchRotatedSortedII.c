#include <stdio.h>
#include <stdlib.h>

int searchRotatedSorted(int *arr, int len, int x){
    int l = 0, h = len-1, mid, ans = -1;
    while(l<=h){
        mid = l + (h-l)/2;
        if(arr[mid] == x){ans = mid; break;}

        // One extra condition
        if(arr[l] == arr[mid] && arr[mid] == arr[h]){
            l++; h--; continue;
        }

        if(arr[l] <= arr[mid]){
            if(arr[l]<=x && arr[mid]>x){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
            if(arr[mid]<x && arr[h]>=x){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
    }
    return ans;
}

int main(){
    int arr[] = {3,1,2,3,3,3,3}, len = sizeof(arr)/sizeof(arr[0]);
    int target = 1;
    int res = searchRotatedSorted(arr, len, target);
    if(res == -1){printf("\n-->> FALSE!\n\n");}
    else{printf("\n-->> TRUE!\n\n");}
    return 0;
}