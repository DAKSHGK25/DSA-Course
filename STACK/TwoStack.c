#include <stdio.h>
#include <stdlib.h>

void push1(int *a, int x, int *t1, int *t2){
    if(*t1 > *t2){
        printf("Stack 1 Overflow!\n");
        return;
    }
    a[(*t1)++] = x;
}

void push2(int *a, int x, int *t1, int *t2){
    if(*t2 < *t1){
        printf("Stack 2 Overflow!\n");
        return;
    }
    a[(*t2)--] = x;
}

void display(int *a, int n, int t1, int t2){
    for(int i=0; i<t1; i++){
        printf("%d ", a[i]);
    }
    printf(" ....  ");
    for(int j=t2+1; j<n; j++){
        printf("%d ", a[j]);
    }
}

int main(){
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    int arr[n];
    int top1 = 0, top2 = n-1;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    int ch;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch == 4){break;}
        switch(ch){
            case 1:
                printf("");
                int choice;
                while(1){
                    printf("Enter your choice (0 -- EXIT | 1 -- PUSH): ");
                    scanf("%d", &choice);
                    if(choice == 0){
                        break;
                    }
                    int key, m;
                    printf("Enter Stack Index(1 or 2): ");
                    scanf("%d", &m);
                    if(m > 2 || m < 1){printf("Invalid Stack Index!\n");break;}
                    printf("Enter an element to Push into the Stack: ");
                    scanf("%d", &key);
                    (m==1)?push1(arr, key, &top1, &top2):push2(arr, key, &top1, &top2);
                }
                break;
            case 2:
                break;
            case 3:
                printf("--- 2 Stack into a single Array ---\n");
                display(arr, n, top1, top2);
                break;
        }
    }
    printf("EXITING...:)");
    return 0;
}