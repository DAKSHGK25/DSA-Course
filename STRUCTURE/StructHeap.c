#include <stdio.h>
#include <stdlib.h>

typedef struct rec {
    int l;
    int b;
} r;

r * Structheap() {
    r *ptr;
    ptr = (r *)malloc(sizeof(r));

    ptr->l = 10;
    ptr->b = 5;

    return ptr;
}

int main() {
    r *p;
    p = Structheap();
    printf("Area: %d\n", p->l*p->b);
    return 0;
}