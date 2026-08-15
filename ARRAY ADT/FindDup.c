#include <stdio.h>

int main(){
    int a[] = /*{3,6,8,8,10,12,15,15,15,20}*/{8,3,6,4,6,5,6,8,2,7};
    int n = sizeof(a)/sizeof(a[0]);
    int dup;    //Stores current Duplicate value
    printf("Duplicates are --> ");
    for(int i=0; i<n-1; i++){
        if(a[i]==a[i+1] && a[i]!=dup){
            printf("%d ", a[i]);
            dup = a[i];
        }
    }
    //Method-1
    // int c = 1; int dup1;
    // for(int i=0; i<n-1; i++){
    //     if(a[i]==a[i+1] && a[i]!=dup1){
    //         c++; dup1 = a[i];
    //     }
    //     else if(a[i]==a[i+1] && a[i]==dup1){
    //         c++;
    //     }
    //     else if(a[i]!=a[i+1] && a[i]==dup1){
    //         printf("\nDuplicate %d is repeated %d time(s).", a[i], c);
    //         c = 1;
    //     }
    // }
    //Method-2 --> Using Hash Table
    int h[n];
    for(int i=0; i<n; i++){
        h[i] = 0;
    }
    int c;
    for(int i=0; i<n; i++){
        if(h[i]!=1){
            h[i] = 1;
            c = 1;
            for(int j=i+1; j<n; j++){
                if(a[i] == a[j]){
                    h[j] = 1;
                    c++;
                }
            }
            if(c>1){
                printf("\nDuplicate %d is repeated %d time(s).", a[i], c);
            }
        }
    }
    return 0;
}