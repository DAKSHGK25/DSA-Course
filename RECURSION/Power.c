#include <stdio.h>

// int power(int a, int b) {
//     if (b == 1) {
//         return a;
//     }
//     else {
//         return a*power(a, b-1);
//     }
// }

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power(a*a, b/2);
    }
    else {
        return a*power(a*a, b/2);
    }
}

int main() {
    int a, b;
    printf("Enter the BASE: ");
    scanf("%d", &a);
    printf("Enter the EXPONENT: ");
    scanf("%d", &b);
    printf("%d raised to %d is: %d\n", a, b, power(a,b));
    return 0;
}