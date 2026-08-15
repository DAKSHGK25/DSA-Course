#include <stdio.h>
#include <stdlib.h>

int main(){
    /*realloc() --> ReAllocation of Memory
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
    int size;
    printf("\nRe-initialise the Array size: ");
    scanf("%d", &size);
    p = (int *)realloc(p, size);
    printf("Enter %d elements to be stored in Array: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", &(*(p+i)));
    }
    printf("The values stored in array (after re-initialising) using realloc: ");
    for(int i=0; i<size; i++){
        printf("%d ", *(p+i));
    }
    free(p);
    return 0;
}