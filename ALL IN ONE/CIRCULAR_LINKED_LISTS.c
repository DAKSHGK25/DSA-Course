#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL, *last = NULL;

void create(int A[], int n){
    for(int i=0; i<n; i++){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        if(head==NULL){
            head = P;
            last = P;
        }
        else{
            last->next = P;
            last = P;
        }
    }
}

//ITERATIVE -->
void Idisplay(struct Node *P){
    do{
        printf("%d ", P->data);
        P = P->next;
    }while(P!=head);
}

//RECURSIVE -->
void Rdisplay(struct Node *P){
    static int flag = 0;
    if(P!=head){
        printf("%d ", P->data);
        Rdisplay(P->next);
    }
    else{
        if(flag==0){
            printf("%d ", P->data);
            flag=1;
            Rdisplay(P->next);
        }
    }
}

void circularCheck(struct Node *P, struct Node *Q){
    do{
        Q = Q->next;
        P = P->next;
        Q = Q?Q->next:Q;
    }while(P!=Q && Q!=NULL);
    if(P==Q){
        printf("It's Circular!\n");
    }
    else if(Q==NULL){
        printf("It's Linear!\n");
    }
}

int main(){
    int A[] = {1, 2, 3, 4, 5, 6};
    create(A, 6);
    struct Node *t1, *t2;
    t1 = head;
    t2 = head->next->next->next->next->next;
    t2->next=t1;
    circularCheck(head, head);
    Rdisplay(head);
    return 0;
}