#include <stdio.h>

void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Numbers inside the function are a: %d and b: %d.\n", a, b);
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Numbers inside the function are a: %d and b: %d.\n", *a, *b);
}


int main() {
    /*  returntype function_name (parameters) {
            //block of code;
    }
    */
    //SWAPPING OF NUMBERS
    int a, b;
    printf("Result by PASS BY VALUE -->\n");
    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);
    printf("Numbers outside the function before the function call are a: %d and b: %d.\n", a, b);
    swap1(a, b);
    printf("Numbers outside the function after the function call are a: %d and b: %d.\n", a, b);

    int c, d;
    printf("Result by PASS BY REFERENCE -->\n");
    printf("Enter 2 numbers: ");
    scanf("%d %d", &c, &d);
    printf("Numbers outside the function before the function call are a: %d and b: %d.\n", c, d);
    swap2(&c, &d);
    printf("Numbers outside the function after the function call are a: %d and b: %d.\n", c, d);


    return 0;
}