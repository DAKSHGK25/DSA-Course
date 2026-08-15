#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
        char name[30];
        int roll;
        char branch[20];
    } s;

int main() {
    int a[5] = {2, 4, 6, 8, 10};
    int *ptr = a;
    printf("Array elements: ");
    for (int i=0; i<5; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    //In case of Structures:
    s s1 = {"XYZ", 10, "AIML"};
    s *ptr1 = &s1;

    printf("Name: %s\n", (*ptr1).name);
    printf("Roll No.: %d\n", ptr1->roll);
    printf("Branch: %s\n", ptr1->branch);

    //To create pointer in heap memory dynamically
    s *ptr2 = (s *)malloc(sizeof(s));
    strcpy(ptr2->name, "ABC");
    ptr2->roll = 20;
    strcpy(ptr2->branch, "MECHANICAL");

    printf("Name: %s\n", (*ptr2).name);
    printf("Roll No.: %d\n", ptr2->roll);
    printf("Branch: %s\n", ptr2->branch);
    free(ptr2); //Free up dynamic memory

    return 0;
}