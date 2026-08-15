#include <stdio.h>

void strcopy(char s[], char r[]){
    static int i=0;
    //Iterative -->
    // while(r[i]!='\0'){
    //     s[i] = r[i];
    //     i++;
    // }
    // s[i]='\0';

    //Pointer Arithematic -->
    // char *p = s, *q = r;
    // while(*(r+i)!='\0'){
    //     *(p+i) = *(q+i);
    //     i++;
    // }
    // *(p+i) = '\0';

    //Recursive -->
    if(r[i]=='\0'){
        s[i] = '\0';
        return;
    }
    else{
        s[i] = r[i];
        i++;
        strcopy(s, r);
    }
}

int main(){
    char r[50], s[50];
    printf("Enter a string: ");
    scanf("%[^\n]s", r);
    strcopy(s, r);
    printf("The copied string: %s\n", s);
    return 0;
}