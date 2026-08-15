#include <stdio.h>

int main(){
    //Method-1 -->
    // int b[] = {6,7,11,12,15,16,17,18,19};
    // int diff = b[0]-0;
    // int size = sizeof(b)/sizeof(b[0]);
    // for(int i=0; i<size; i++){
    //     if(/*b[i]-i != diff && */b[i]-i > diff){
    //         while(diff < b[i]-i){
    //             printf("Missing Element: %d\n", diff+i);
    //             diff++;
    //         }
    //     }
    // }

    //Method-2 --> Using HASH TABLE
    int a[] = {3,7,4,9,12,6,1,11,2,10};
    int max = a[0];
    for(int i=1; i<sizeof(a)/sizeof(a[0]); i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    int f[max];
    for(int i=0; i<=max; i++){
        f[i] = 0;
    }
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        f[a[i]] = 1;
    }
    for(int i=1; i<=max; i++){
        if(f[i]!=1){
            printf("Missing Element: %d\n", i);
        }
    }
    return 0;
}