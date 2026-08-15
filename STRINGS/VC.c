#include <stdio.h>

int main(){
    char s[] = "How are you?";
    int v=0, c=0, n = sizeof(s)/sizeof(s[0]);
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){v++;}
        else if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122){c++;}
    }
    printf("Vowel count: %d\n", v);
    printf("Consonant count: %d\n", c);
    return 0;
}