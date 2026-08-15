#include <stdio.h>

int main(){
    char s[] = "How  are   you?";
    int c = 0, i = 0;
    while(s[i]){
        if(s[i]==' ' && s[i-1]!=' '){c++;}  //Considering WHITESPACES
        i++;
    }
    printf("Word(s) count: %d\n", c+1); //Total number of words == number of spaces + 1
    return 0;
}