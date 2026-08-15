#include <stdio.h>

typedef struct rectangle {
    int l;
    int b;
} r;    //Alias Name

int main() {
    r rec1 = {5, 4};
    printf("Length: %d\n", rec1.l);
    printf("Breadth: %d\n", rec1.b);
    printf("Area: %d\n", rec1.l * rec1.b);
    printf("Size of Structure: %lu\n", sizeof(rec1));   //%lu --> for long unsigned
    return 0;
}