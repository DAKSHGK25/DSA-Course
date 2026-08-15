#include <stdio.h>

int main() {
    int n;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) {
        printf("Enter Element No.%d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Array is: ");
    int *ptr = a;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
    return 0;
}