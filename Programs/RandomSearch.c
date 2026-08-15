#include <stdio.h>
#include <stdlib.h> //Includes the rand() function
#include <time.h>   //Includes the time() function  //Returns the seconds that have passed till date since JANUARY 1, 1970

int main(){
    srand(time(NULL));  //To change the Random Number whenever the program is run
    //printf("%d", rand());
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int ele;
    printf("Enter the Search element: ");
    scanf("%d", &ele);
    int f = 0;
    while(f == 0){
        int index = rand() % n;
        for(int i=0; i<n; i++){
            if (a[index] == ele){
                f = 1;
                printf("Element %d found at index %d!\n", ele, index);
                break;
            }
        }
    }
    return 0;
}