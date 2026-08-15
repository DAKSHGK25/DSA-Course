#include <stdio.h>

int strlen(char *a){
    //Iterative -->
    int len = 0;
    // for(int i=0; a[i]!='\0'; i++){
    //     len++;
    // }
    int i=0;
    // while(a[i]!='\0'){
    //     len++;
    //     i++;
    // }

    //Pointer Arithematic -->
    //char *p = a;
    // while(*(p+i)!='\0'){
    //     len++;i++;
    // }

    //Recursive -->
    if(*(a+i) == '\0'){return 0;}
    else{
        i++;
        return 1+strlen(a+i);
    }
    //return len;
}

int main(){
    char s[50];
    printf("Enter a string: ");
    scanf("%[^\n]s", s);
    printf("Length of the string: %d\n", strlen(s));
    return 0;
}