// Approach A. Insert in same order as entered by the user, delete acc. to the priority
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("\nEnter the no. of elements to be stored: "); scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter %d elements: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    int prio[n], lenprio=0, arrlen = n;    // Array to store elements acc. to priority
    while(lenprio!=n){
        int min = arr[0], index = 0;
        for(int i=0; i<arrlen; i++){
            if(min > arr[i]){min = arr[i]; index = i;}
        }
        prio[lenprio++] = arr[index];
        for(int i=index; i<arrlen-1; i++){
            arr[i] = arr[i+1];
        }
        arrlen--;
    }
    printf("\n--> The elements in order of their Priority is (smaller the no., higher the priority): ");
    for(int i=0; i<lenprio; i++){
        printf("%d ", prio[i]);
    }
    printf("\n\n");
    return 0;
}