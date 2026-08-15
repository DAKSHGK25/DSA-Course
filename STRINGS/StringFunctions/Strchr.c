#include <stdio.h>

char *strchar(char s[], char ch){
    char *p = NULL;
    //Iterative -->
    //int i=0;
    // while(s[i]!='\0'){
    //     if(s[i] == ch){
    //         p = s+i;
    //         break;
    //     }
    //     i++;
    // }

    //Pointer Arithematic -->
    // char *q = s;
    // while (*(q+i)!='\0'){
    //     if(*(q+i)==ch){
    //         p=q+i;
    //     }
    //     i++;
    // }

    //Recursive -->
    static int i=0;
    if(*(s+i)==ch){
        p = s+i;
        return p;
    }
    else if(*(s+i)=='\0'){
        return p;
    }
    else{
        i++;
        strchar(s, ch);
    }
    //return p;
}

int main(){
    char s[50], ch;
    printf("Enter a string: ");
    scanf("%s", s);
    printf("Enter a character: ");
    scanf(" %c", &ch);
    char *ptr = strchar(s, ch);
    printf("%p\n", ptr);
    if(ptr != NULL){
        printf("Character '%c' was found in the string '%s' at address %p\n", *ptr, s, ptr);
    }
    else{
        printf("Character '%c' was not found in the string '%s'\n", *ptr, s);
    }
    return 0;
}