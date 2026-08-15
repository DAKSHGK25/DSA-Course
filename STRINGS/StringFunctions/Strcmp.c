#include <stdio.h>
#include <string.h>

int strcomp(char s[], char r[]){
    int i=0;
    //Method-1 -->
    // while(!(s[i]=='\0' && r[i]=='\0')){
    //     if(s[i]>r[i]){
    //         return 1;
    //     }
    //     else if(s[i]<r[i]){
    //         return -1;
    //     }
    //     i++;
    // }
    // if(s[i]=='\0'&&r[i]=='\0'){
    //     return 0;
    // }
    // else if(s[i]=='\0'){
    //     return -1;
    // }
    // else{
    //     return 1;
    // }

    //Method-2 -->
    while(s[i]==r[i] && s[i]!='\0'){
        i++;
    }
    if(s[i]>r[i]){return 1;}
    else if(s[i]<r[i]){return -1;}
    else{return 0;}
}

int main(){
    char s[50], r[50];
    printf("Enter a string1: ");
    scanf("%[^\n]s", s);
    printf("Enter a string2: ");
    scanf(" %[^\n]s", r);
    printf("Result on Comparison: %d\n", strcomp(s,r));
    printf("Result on Comparison: %d\n", strcmp(s,r));
    return 0;
}