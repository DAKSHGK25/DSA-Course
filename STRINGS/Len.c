#include <stdio.h>

int len(char s[]){
    int i = 0, l = 0;
    while(s[i]){
        l++;i++;
    }
    return l;
}

int main(){
    char name[] = {'W','e','l','c','o','m','e','\0'};   //char name[] = "Welcome";
    printf("Legth of the string '%s' is: %d\n", name, len(name));
    return 0;
}