#include <stdio.h>
#include <stdlib.h> // The header file which includes the DMA functions

int main(){
    /*malloc() --> Memory Allocation
    Default values stored are GARBAGE VALUES
    */
    int n;
    printf("Enter the size of Array to be malloced: ");
    scanf("%d", &n);
    int *p = (int *)malloc(n*sizeof(int));
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