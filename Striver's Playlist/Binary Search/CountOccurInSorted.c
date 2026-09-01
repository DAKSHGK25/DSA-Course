// Just find the first occurence (f) and last occurence (l) index of given element in the array and no. of occurences --> l-f+1

#include <stdio.h>
#include <stdlib.h>

int firstOccurrence(int *arr, int len, int x){
    int l = 0, h = len-1, mid, ans = -1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] == x){
            ans = mid;
            h = mid-1;
        }
        else if(arr[mid] < x){l = mid+1;}
        else{h = mid-1;}
    }
    return ans;
}

int lastOccurrence(int *arr, int len, int x){
    int l = 0, h = len-1, mid, ans = -1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] == x){
            ans = mid;
            l = mid+1;
        }
        else if(arr[mid] < x){l = mid+1;}
        else{h = mid-1;}
    }
    return ans;
}

int main(){
    int arr[] = {2,4,6,8,8,8,11,13}, len = sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int first = firstOccurrence(arr, len, key);
    int last = lastOccurrence(arr, len, key);
    if(first == -1){
        printf("\n-->> Key %d is not found in the array!\n", key);
        printf("-->> Count of Occurences: 0\n\n");
    }
    else{
        printf("\n-->> First Occurrence: %d\n", first);
        printf("-->> Last Occurrence: %d\n", last);
        printf("-->> Count of Occurences: %d\n\n", last-first+1);
    }
    return 0;
}