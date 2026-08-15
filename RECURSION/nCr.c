#include <stdio.h>

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n*fact(n-1);
    }
}

int nCr(int n, int r) {
    int nf = fact(n);   //n!
    int rf = fact(r);   //r!
    int nmrf = fact(n-r);   //(n-r)!
    return nf/(rf*nmrf);
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