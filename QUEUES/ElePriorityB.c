// Approach B. Insert acc. to the priority, then keep on deleting element from the end
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
    int prio[n], len = 0, i = 0;
    prio[len] = arr[i]; len++; i++;
    while(len != n){
        int f = 0;
        for(int j=len-1; j>=0; j--){
            if(prio[j]<arr[i]){
                prio[j+1] = prio[j];
            }
            else{
                prio[j+1] = arr[i];len++;
                f++; break;
            }
        }
        if(f != 1){prio[0] = arr[i];len++;}
        i++;
    }
    printf("\n--> The elements in order of their Priority is (smaller the no., higher the priority): ");
    for(int i=len-1; i>=0; i--){
        printf("%d ", prio[i]);
    }
    printf("\n\n");
    return 0;
}