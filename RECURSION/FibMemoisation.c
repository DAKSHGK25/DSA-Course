#include <stdio.h>

int F[10];
int fib(int n) {
    if (n == 0 || n == 1) {
        F[n] = n;
        return n;
    }
    else {
        if (F[n-1] == -1) {
            F[n-1] = fib(n-1);
        }
        if (F[n-2] == -1) {
            F[n-2] = fib(n-2);
        }
        F[n] = F[n-1] + F[n-2];
        return F[n];
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i=0; i<10; i++) {
        F[i] = -1;
    }
    printf("Element at Index No.%d of Fibonacci Series is: %d\n", n, fib(n));
    return 0;
}