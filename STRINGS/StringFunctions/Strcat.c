#include <stdio.h>

void strconcat(char *s, char *r){
    int l = 0;
    while(*(s+l)!='\0'){
        l++;
    }
    //Iterative -->
    // int i=0; //--> For both iterative as well as pointer
    // while(r[i]!='\0'){
    //     s[l+i] = r[i];
    //     i++;
    // }
    // s[l+i] = '\0';

    //Pointer Arithematic
    // char *p = s, *q = r;
    // while()

    //Recursive -->
    static int i = 0; //--> For recursive
    if(*(r+i)=='\0'){
        *(s+l+i) = '\0';
        return;
    }
    else{
        *(s+l+i) = *(r+i);
        i++;
        strconcat(s, r);
    }
}

int main(){
    char s[50], r[50];
    printf("Enter a string1: ");
    scanf("%[^\n]s", s);
    printf("Enter a string2: ");
    scanf(" %[^\n]s", r);
    strconcat(s, r);
    printf("Concatenated string: %s\n", s);
    return 0;
}