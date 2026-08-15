#include <stdio.h>

typedef struct rectangle {
    int l;
    int b;
} r;

int area(r *r1) {
    return r1->l * r1->b;
}

int main() {
    r r1 = {10, 5};
    printf("Area: %d", area(&r1));
    return 0;
}