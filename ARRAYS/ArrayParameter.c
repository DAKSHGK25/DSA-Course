#include <stdio.h>

void disp1(int a[5], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}

void disp2(int *ptr, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
}

int main() {
    int a[5] = {2, 4, 6, 8, 10};
    disp1(a, 5);
    printf("\n");
    disp2(a, 5);
    return 0;
}