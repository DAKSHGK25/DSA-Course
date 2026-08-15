#include <stdio.h>

int main(){
    int a[] = /*{6,8,3,10,16,7,5,2,9,14};*/{1,3,4,5,6,8,9,10,12,14};
    int target = 10, n = sizeof(a)/sizeof(a[0]), c=0;
    //Method-1 --> Brute Force
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(a[i]+a[j] == target){
    //             printf("Pair found --> (%d,%d)\n", a[i],a[j]);
    //             c++;
    //         }
    //     }
    // }
    // if(c==0){
    //     printf("No pair found!");
    // }
    //Method-2 --> Optimised Solution --> Unsorted Array
    // int max = a[0];
    // for(int i=1; i<n; i++){
    //     if(max<a[i]){
    //         max=a[i];
    //     }
    // }
    // int h[max];
    // for(int i=0; i<max; i++){
    //     h[i] = 0;
    // }
    // for(int i=0; i<n; i++){
    //     if(h[a[i]] == 0){
    //         h[a[i]] = 1;
    //         if(h[target-a[i]] == 1 && a[i]!=target-a[i]){
    //             printf("Pair found --> (%d,%d)\n", a[i], target-a[i]);
    //         }
    //     }

    // }
    //Method-3 --> Sorted Array
    int i=0, j=n-1;
    while(i<j){
        if(a[i]+a[j] == target){
            printf("Pair found --> (%d,%d)\n", a[i],a[j]);
            i++;//j--;
        }
        else if(a[i]+a[j] > target){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}