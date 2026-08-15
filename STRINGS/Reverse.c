#include <stdio.h>

//Using Auxillary array
void rev1(char s[], char r[], int n){
    int j=0;
    for(int i=n-2; i>=0; i--){
        r[j] = s[i];
        j++;
    }
    r[j] = '\0';
}

//Without using Auxillary array
void rev2(char s[], int n){
    for(int i=0; i<=n/3; i++){
        int temp = s[i];
        s[i] = s[n-i-2];
        s[n-i-2] = temp;
    }
}

int main(){
    char s[] = "JAVA";
    int n = sizeof(s)/sizeof(s[0]);
    char r[n];
    rev2(s,n);
    printf("Reversed string: %s\n", s);
    return 0;
}