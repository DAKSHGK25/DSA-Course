#include <stdio.h>
#include <string.h>

void rev(char r[], int n){
    for(int i=0; i<=n/3; i++){
        char temp = r[i];
        r[i] = r[n-i-2];
        r[n-i-2] = temp;
    }
}

int main(){
    char s[50]; int len = 0;
    printf("Enter a string: ");
    scanf("%s", s);
    for(int i=0; s[i]!='\0'; i++){
        len++;
    }
    len++;
    char r[len];
    strcpy(r,s);
    rev(r,len);
    if(!(strcmp(r,s))){
        printf("It's a PALINDROME!");
    }
    else{
        printf("It's not a PALINDROME!");
    }
    return 0;
}