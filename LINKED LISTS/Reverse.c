#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void insert(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;
    if(first == NULL){
        first = P;
        last = P;
    }
    else{
        last->next = P;
        last = P;
    }
}

void display(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

//Using Auxillary array and the Reverse copying
void reverse(struct Node *P, int n){
    int A[n], j = 0; struct Node *Q = P;
    while(Q){
        A[j] = Q->data;
        Q = Q->next;j++;
    }
    for(int i=n-1; i>=0; i--){
        P->data = A[i];
        P = P->next;
    }
}

//Reversing by Sliding Pointers
void reverseSliding(struct Node *P){
    struct Node *Q = NULL, *R = NULL;
    while(P){
        R = Q;//Sliding Pointer
        Q = P;//Sliding Pointer
        P = P->next;//Sliding Pointer
        Q->next = R;
    }
    first = Q;
}

//Reversing by Recursion
void reverseRecursive2(struct Node *R, struct Node *Q, struct Node *P){
    if(P == NULL){
        first = Q;
        return;
    }
    else{
        R = Q;
        Q = P;
        P = P->next;
        Q->next = R;
        return reverseRecursive2(R, Q, P);
    }
}

//Recursion --> Better Way
void reverseRecursion(struct Node *Q, struct Node *P){
    if(P != NULL){
        reverseRecursion(P, P->next);
        P->next = Q;
    }
    else{
        first = Q;
    }
}

int main(){
    int ch, n = 0;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        n++;
        int key;
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert(first, key);
    }
    printf("-- LINKED LIST --\n");
    display(first);
    //reverseSliding(first);
    reverseRecursion(NULL, first);
    printf("\n-- REVERSED LINKED LIST --\n");
    display(first);
    return 0;
}