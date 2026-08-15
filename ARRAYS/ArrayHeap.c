#include <stdio.h>
#include <stdlib.h>

int *arr(int n) {
    int *p;
    p = (int *)malloc(n*sizeof(int));

    for (int i=0; i<n; i++) {
        p[i] = i+1;
    }

    return p;
}

int main() {
    int *ptr, n = 5;
    ptr = arr(n);
    for (int i=0; i<n; i++) {
        printf("%d ", ptr[i]);
    }
    return 0;
}