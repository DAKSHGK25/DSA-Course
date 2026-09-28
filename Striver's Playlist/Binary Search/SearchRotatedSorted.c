#include <stdio.h>
#include <stdlib.h>

int searchRotatedSorted(int *arr, int len, int x){
    int l = 0, h = len-1, mid, ans = -1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] == x){ans = mid; break;}
        if(arr[l] <= arr[mid]){  // The left half is Sorted
            if(arr[l] <= x && arr[mid] >= x){ // The target in on the left half
                h = mid-1;
            }
            else{   // The target is on the right half
                l = mid+1;
            }
        }
        else{   // The right half is Sorted
            if(arr[mid] <= x && arr[h] >= x){ // The target in on the right half
                l = mid+1;
            }
            else{   // The target is on the left half
                h = mid-1;
            }
        }
    }
    return ans;
}

int main(){
    int arr[] = {7,8,9,1,2,3,4,5,6}, len = sizeof(arr)/sizeof(arr[0]);  // The array conatins no duplicates
    int target = 18;
    int pos = searchRotatedSorted(arr, len, target);
    if(pos == -1){printf("\n-->> Target is not found in the Rotated Sorted array!\n\n");}
    else {printf("\n-->> Target is found in the Rotated Sorted array at index %d!\n\n", pos);}
    return 0;
}