#include <stdio.h>

int main(){
    //Method-1 --> If its first n Natural Numbers
    int a[] = {1,2,3,4,5,6,8,9,10,11,12};
    int total = ((12)*(12+1))/2;
    int sum = 0;
    for(int i=0; i<11; i++){
        sum += a[i];
    }
    printf("Missing Element: %d\n", total-sum);

    //Method-2 --> It its any random numbers but are continuous
    int b[] = {6,7,8,9,10,11,13,14,15,16,17};
    int diff = b[0]-0;
    for(int i=1; i<11; i++){
        if(b[i]-i != diff){
            printf("Missing Element: %d\n", diff+i);
            break;
        }
    }
    int s1 = ((b[0]-1)*(b[0]))/2;
    int s2 = (b[10]*(b[10]+1))/2;
    int sum1 = 0;
    for(int i=0; i<11; i++){
        sum1 += b[i];
    }
    printf("Missing Element: %d\n", s2-s1-sum1);
    return 0;
}