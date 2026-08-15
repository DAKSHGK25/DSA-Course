#include <stdio.h>

float taylor(int x, int n) {
    static float p = 1;
    static float f = 1;
    float r;
    if (n == 0) {
        return 1.0;
    }
    else {
        r = taylor(x, n-1);
        p *= x;
        f *= n;
        return r+(float)(p/f);
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