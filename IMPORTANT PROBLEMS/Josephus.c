#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL, *last = NULL;

void insert(int x){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = x;
    P->next = NULL;

    if(head == NULL){
        head = P;
        last = P;
    }
    else{
        last->next = P;
        last = P;
    }
}

void delete(struct Node **R, struct Node **P){
    if(*P == head){
        head = head->next;
        last->next = head;
        return;
    }
    if(*P == last){
        (*R)->next = head;
        last = *R;
        free(*P);
        return;
    }
    (*R)->next = (*P)->next;
    free(P);
}

void display(){
    struct Node *P = head;
    do{
        printf("%d -> ", P->data);
        P = P->next;
    }while(P!=head);
    printf("NULL\n");
}

int length(){
    struct Node *P = head;
    int c = 0;
    do{
        c++;
        P = P->next;
    }while(P!=head);
    return c;
}

//int start = -1;
int josephus(int n, int k){
    struct Node *P = head, *R = last;
    while(P->next != P){
        for(int i=1; i<=k-1; i++){
            R = P;
            P = P->next;
        }
        delete(&R, &P);
        P = R->next;
    }
    return P->data;
}

int main(){
    int n;
    printf("Enter the Number of People: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        insert(i);
    }
    last->next = head;
    int k;
    printf("Enter a value of k (index of person to be removed): ");
    scanf("%d", &k);
    display();
    printf("The Survivor is: %d\n", josephus(n, k));
    return 0;
}