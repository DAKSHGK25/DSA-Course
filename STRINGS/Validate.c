#include <stdio.h>

int main(){
    char s[50];
    printf("Enter a string: ");
    scanf("%s", s);
    int n = sizeof(s)/sizeof(s[0]);
    for(int i=0; s[i]!='\0'; i++){
        if(!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57))){
            printf("It's an INVALID string!");
            return 0;
        }
    }
    printf("It's a VALID string!");
    return 0;
}