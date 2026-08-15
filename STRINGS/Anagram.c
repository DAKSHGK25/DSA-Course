#include <stdio.h>
#include <string.h>

int anagram(char s[], char r[], int f[]){
    int i=0;
    while(s[i]!='\0'){
        f[s[i]-97]++;
        i++;
    }
    int j=0;
    while(r[j]!='\0'){
        f[r[j]-97]--;
        j++;
    }
    for(int l=0; l<26; l++){
        if(f[l]!=0){
            return 0;
        }
    }
    return 1;
}

int main(){
    char s[50], r[50];
    printf("Enter the string1: ");
    scanf("%[^\n]s", s);
    printf("Enter the string2: ");
    scanf(" %[^\n]s", r);
    int f[26];
    for(int i=0; i<26; i++){
        f[i] = 0;
    }
    if(strlen(s)!=strlen(r)){
        printf("The strings are not ANAGRAMS!");
    }
    else{
        int res = anagram(s, r, f);
        if(res == 1){
            printf("The strings are ANAGRAMS!");
        }
        else{
            printf("The strings are not ANAGRAMS!");
        }
    }
    return 0;
}