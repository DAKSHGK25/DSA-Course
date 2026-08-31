// Floor -->> largest element 'ele' in an array such that ele <= n ; n - any given number
// Ceil -->> smallest element 'ele' in an array such that ele >= n ; n - any given number

#include <stdio.h>

int Ceil(int *arr, int len, int x){
    int l = 0, h = len-1, mid, ceil = -1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] >= x){
            ceil = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ceil;
}

int Floor(int *arr, int len, int x){
    int l = 0, h = len-1, mid, floor = -1;
    while(l <= h){
        mid = (l+h)/2;
        if(arr[mid] <= x){
            floor = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return floor;
}

int main(){
    int arr[] = {10,20,25,30,40,50}, len = sizeof(arr)/sizeof(arr[0]);
    int f = Floor(arr, len, 25), c = Ceil(arr, len, 25);
    if(f != -1){ printf("\n-->> Floor: %d\n\n", arr[f]);}
    else{ printf("\n-->> Floor value not found!\n\n");}
    if(c != -1){ printf("\n-->> Ceil: %d\n\n", arr[c]);}
    else{ printf("\n-->> Ceil value not found!\n\n");}
    return 0;
}