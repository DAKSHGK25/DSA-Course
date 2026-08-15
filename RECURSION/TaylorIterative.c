#include <stdio.h>

int main() {
    int x, n;
    printf("Enter a number (for exponent of e): ");
    scanf("%d", &x);
    printf("Enter the maximum power of nth term: ");
    scanf("%d", &n);
    float res = 1;
    for (int i=n; i>=1; i--) {
        res = 1 + (((float)x/i) * res);
    }
    printf("Value of e raised to %d by TAYLOR SERIES is: %f\n", x, res);
    return 0;
}