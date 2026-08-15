#include <stdio.h>

typedef struct rectangle {
    int l;
    int b;
} r;

void initialise(r *r1, int length, int breadth) {
    r1->l = length;
    r1->b = breadth;
}

int area(r r1) {
    return r1.l * r1.b;
}

void changelength(r *r1, int newlen) {
    r1->l = newlen;
}

int main() {
    r r1;

    initialise(&r1, 10, 5);
    printf("Length: %d\n", r1.l);
    printf("Breadth: %d\n", r1.b);

    printf("Area: %d\n", area(r1));

    changelength(&r1, 20);
    printf("Length changed to: %d\n", r1.l);

    printf("New Area: %d\n", area(r1));

    return 0;
}