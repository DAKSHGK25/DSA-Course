#include <stdio.h>

int nCr(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    else {
        return nCr(n-1, r-1) + nCr(n-1, r);
    }
}

int main() {
    int n, r;
    printf("Enter the value of n (in nCr): ");
    scanf("%d", &n);
    printf("Enter the value of r (in nCr and r<=n): ");
    scanf("%d", &r);
    printf("Value of nCr is: %d\n", nCr(n,r));
    return 0;
}