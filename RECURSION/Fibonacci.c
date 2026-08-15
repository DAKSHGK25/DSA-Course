#include <stdio.h>

//RECURSIVE FUNCTION
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

//ITERATIVE FUNCTION
// int fib(int n) {
//     int a = 0; int b = 1; int c;
//     if (n == 0) {
//         return 0;
//     }
//     for (int i=1; i<n; i++) {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return c;
// }

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Index No.%d of Fibonacci Series is: %d\n", n, fib(n));
    return 0;
}