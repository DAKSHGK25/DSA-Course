#include <stdio.h>
#include <string.h>

int compare(char s[], char r[]){
    int i=0;
    while(s[i]!='\0' && r[i]!='\0'){
        if(s[i] > r[i]){
            return 1;
        }
        else if(s[i] < r[i]){
            return -1;
        }
        i++;
    }
    if(s[i] == '\0' && r[i] == '\0'){
        return 0;
    }
    else if(s[i] == '\0'){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    char s[50], r[50];
    printf("Enter 2 strings: ");
    scanf("%s %s", s,r);
    printf("Result: %d\n", compare(s,r));
    printf("Result: %d\n", strcmp(s,r));
    return 0;
}