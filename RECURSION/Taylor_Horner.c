#include <stdio.h>

float taylor(int x, int n) {
    static float res = 1;
    if (n == 0) {
        return res;
    }
    else {
        res = 1 + (((float)x/n) * res);
        return taylor(x, n-1);
    }
}

int main() {
    int x, n;
    printf("Enter a number (for exponent of e): ");
    scanf("%d", &x);
    printf("Enter the maximum power of nth term: ");
    scanf("%d", &n);
    printf("Value of e raised to %d by TAYLOR SERIES is: %f\n", x, taylor(x, n));
    return 0;
}