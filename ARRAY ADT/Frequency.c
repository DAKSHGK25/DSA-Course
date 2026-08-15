#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of Array elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = -1;
    }
    for(int i=0; i<n; i++){
        if(b[i] != 1){
            b[i] = 1;
            int c = 1;
            for(int j=i+1; j<n; j++){
                if(a[i] == a[j]){
                    c++;
                    b[j] = 1;
                }
            }
            printf("Frequency of %d is: %d\n", a[i], c);
        }
    }
    return 0;
}