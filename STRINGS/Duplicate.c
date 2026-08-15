#include <stdio.h>
#include <string.h>

//Method-1 --> Using Hash
void freq(char s[], int f[], int n){
    for(int i=0; i<n; i++){
        if(f[i]!=1){
            f[i]=1;
            int c=1;
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    f[j]=1;
                    c++;
                }
            }
            if(c>1){
                printf("The character %c is repeated %d times.\n", s[i], c);
            }
        }
    }
}

//Method-2 --> Brute Force
void freq1(char s[], int n){
    for(int i=0; i<n; i++){
        int c=1;
        for(int j=i+1; j<n; j++){
            if(s[j]!=0){
                if(s[i]==s[j]){
                    c++;
                    s[j]=0;
                }
            }
        }
        if(c>1){
            printf("The character %c is repeated %d times.\n", s[i], c);
        }
    }
}

//Bit Manipulation --> BUT WE CANNOT FIND THE COUNT
void freq2(char s[], int l){
    int h = 0, x = 0;
    for(int i=0; i<=l; i++){
        x = 1;
        x = x<<(s[i]-97);
        if((x & h) > 0){  //MASKING - checking 'ON' or 'OFF'
            printf("The character %c is repeated.\n", s[i]);
        }
        else{   //MERGING - setting that bit to 'ON'
            h = x | h;
        }
    }
}

int main(){
    char s[50];
    printf("Enter a string: ");
    scanf("%s", s);
    int l = 0;
    for(int i=0; s[i]!='\0'; i++){
        l++;
    }
    int f[l];
    for(int i=0; i<l; i++){
        f[i] = 0;
    }
    //freq(s,f,l);
    //freq1(s, l);
    freq2(s, l);
    return 0;
}