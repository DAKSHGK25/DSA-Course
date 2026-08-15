#include <stdio.h>
#include <stdlib.h>

//Creating a Node
struct Node{
    int data;
    struct Node *next;  //Self-Referential Pointer
};

int main(){
    struct Node *P;
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = 10;
    P->next = 0;    //NULL
    if(P){
        printf("P points to a Node!\n");
    }
    else{
        printf("P Points to NULL!\n");
    }
    printf("Data: %d\n", P->data);
    printf("Node Pointer pointing to: %p\n", P->next);
    if(!P->next){
        printf("Node Pointer Points to NULL!\n");
    }
    else{
        printf("Node Pointer Points to next NODE!\n");
    }
    return 0;
}