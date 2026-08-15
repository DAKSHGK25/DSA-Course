#include <stdio.h>

void rec1(int n) {
    if (n > 0) {
        printf("%d ", n);
        rec1(n-1);
    }
}

void rec2(int n) {
    if (n > 0) {
        rec2(n-1);
        printf("%d ", n);
    }
}

int main() {
    int x = 5;
    rec1(x);
    printf("\n");
    rec2(x);
    return 0;
}