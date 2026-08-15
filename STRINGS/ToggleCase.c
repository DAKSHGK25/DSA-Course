#include <stdio.h>
#include <stdlib.h>

void CaseChange(char s[], int n){
    for(int i=0; i<n-1; i++){
        if(s[i]>=65 && s[i]<=90){
            s[i] = s[i]+32;
        }
        else if(s[i]>=97 && s[i]<=122){
            s[i] = s[i]-32;
        }
    }
    return;
}

int main(){
    char s[50];
    printf("Enter a string (of mixed case): ");
    scanf("%s", s);
    int n = sizeof(s)/sizeof(s[0]);
    CaseChange(s,n);
    printf("String after Case toggle: %s\n", s);
    return 0;
}