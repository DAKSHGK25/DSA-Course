#include <stdio.h>

// Time Complexity - O(n)
// Space Complexity - O(n)


int sum(int i, int n, int s) {
    if (i > n) {
        return s;
    }
    else {
        return sum(i+1, n, s+i);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of Natural Numbers till %d is: %d\n", n, sum(1, n, 0));
    return 0;
}