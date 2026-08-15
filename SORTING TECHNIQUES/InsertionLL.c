#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void createLL(struct Node **f, struct Node **l, int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key; P->next = NULL;

    if(!(*f)){
        *f = *l = P; return;
    }
    (*l)->next = P;
    *l = P; return;
}

void InsertionSort(struct Node **f, struct Node **l, int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key; P->next = NULL;

    if(!(*f)){
        *f = *l = P; return;
    }
    struct Node *Q = NULL, *R = *f;
    if(R->data > P->data){
        P->next = *f;
        *f = P; return;
    }
    Q = R; R = R->next;
    while(R){
        if(Q->data <= P->data && P->data < R->data){
            P->next = R;
            Q->next = P; return;
        }
        Q = R; R = R->next;
    }
    Q->next = P;
    *l = P;
}

void display(struct Node *P){
    while(P){
        printf("%d -> ", P->data);
        P = P->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *head = NULL, *last = NULL;
    printf("\n<<--- Choices --->>\n");
    printf("1. Insert\n2. EXIT\n");
    printf("<<--------------->>\n"); int ch;
    while(1){
        printf("\n-->> Enter your choice: "); scanf("%d", &ch);
        if(ch == 2){break;}
        printf("\n-->> Enter an element to insert in the LL: "); int ele; scanf("%d", &ele);
        createLL(&head, &last, ele);
    }
    printf("\n-->> LL before Insertion Sort: "); display(head); printf("\n");
    int key;
    printf("\n-->> Enter a key to be inserted: "); scanf("%d", &key);
    InsertionSort(&head, &last, key);
    printf("\n-->> LL after Insertion Sort: "); display(head); printf("\n\n");
    return 0;
}