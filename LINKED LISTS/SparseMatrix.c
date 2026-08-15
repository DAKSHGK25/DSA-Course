#include <stdio.h>
#include <stdlib.h>

struct Node{
    int col;
    int ele;
    struct Node *next;
};

void create(struct Node *A[], int r, int c, int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->col = c; P->ele = key; P->next = NULL;
    if(A[r] == NULL){
        A[r] = P;
    }
    else{
        while(A[r]->next != NULL){
            A[r] = A[r]->next;
        }
        A[r]->next = P;
    }
}

void display(struct Node *A[], int r, int c){
    for(int i=0; i<r; i++){
        struct Node *P = A[i];
        for(int j=0; j<c; j++){
            if(P!=NULL){
                if(P->col == j){
                    printf("%d ", P->ele);
                    P = P->next;
                }
                else{
                    printf("0 ");
                }
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int r, c, n;
    printf("Enter the dimensions of the Sparse Matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the number of Non-Zero elements: ");
    scanf("%d", &n);
    struct Node *A[r];
    for(int i=0; i<r; i++){
        A[i] = NULL;
    }
    int l=1;
    while(l <= n){
        int i, j, key;
        printf("Enter the Row No., Column No. and Element No.%d: ", l);
        scanf("%d %d %d", &i, &j, &key);
        create(A, i, j, key);
        l++;
    }
    printf("---- SPARSE MATRIX USING LINKED LISTS ---\n");
    display(A, r, c);
    printf("-----------------------------------------\n");
    return 0;
}