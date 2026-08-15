#include <stdio.h>

//Method-1
// struct marks{
//     int m1, m2, m3;
// };

// struct student{
//     char name[20];
//     int age;
//     struct marks M;
// };

//Method-2
struct student{
    char name[20];
    int age;
    struct marks{
        int m1, m2, m3;
    }M;
};

int main(){
    struct marks M = {80, 85, 90};
    struct student S = {"ABCD", 20, M};
    printf("%s\n", S.name);
    printf("%d\n", S.age);
    printf("%d\n", S.M.m1);
    printf("%d\n", S.M.m2);
    printf("%d\n", S.M.m3);
    return 0;
}