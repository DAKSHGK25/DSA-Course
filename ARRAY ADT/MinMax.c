#include <stdio.h>

int main(){
    int a[] = {5,8,3,9,6,2,10,7,-1,4};
    int min=a[0], max=a[0], n = sizeof(a)/sizeof(a[0]);
    for(int i=1; i<n; i++){
        if(max<a[i]){max=a[i];}
        if(min>a[i]){min=a[i];}
    }
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    return 0;
}