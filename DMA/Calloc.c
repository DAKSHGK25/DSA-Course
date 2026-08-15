#include <stdio.h>
#include <stdlib.h>

int main(){
    /*calloc() --> Contiguous Allocation
    Default values stored are ZEROS
    */
    int n;
    printf("Enter the size of Array to be calloced: ");
    scanf("%d", &n);
    int *p = (int *)calloc(n, sizeof(int));
    printf("The default values stored in array (before initialising): ");
    for(int i=0; i<n; i++){
        printf("%d ", *(p+i));
    }
    printf("\nEnter %d elements to be stored in Array: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &(*(p+i)));
    }
    printf("The values stored in array (after initialising): ");
    for(int i=0; i<n; i++){
        printf("%d ", *(p+i));
    }
    free(p);
    return 0;
}