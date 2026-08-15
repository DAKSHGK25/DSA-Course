#include <stdio.h>
int a = 0;
int fun(int x) {
    // static int a = 0;
    if (x > 0) {
        a++;
        return fun(x-1)+a;
    }
    return 0;
}

int main() {
    int n = 5;
    int res = fun(n);
    printf("%d", res);
    return 0;
}