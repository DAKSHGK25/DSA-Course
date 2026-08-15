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

void add(int r, int c){
    
}

int main(){
    //Sparse Matrix - 1
    int r1, c1, n1;
    printf("Enter the dimensions of the Sparse Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of Non-Zero elements: ");
    scanf("%d", &n1);
    struct Node *A[r1];
    for(int i=0; i<r1; i++){
        A[i] = NULL;
    }
    int l=1;
    while(l <= n1){
        int i, j, key;
        printf("Enter the Row No., Column No. and Element No.%d: ", l);
        scanf("%d %d %d", &i, &j, &key);
        create(A, i, j, key);
        l++;
    }
    printf("---- SPARSE MATRIX 1 USING LINKED LISTS ---\n");
    display(A, r1, c1);
    printf("-----------------------------------------\n");

    //Sparse Matrix - 2
    int r2, c2, n2;
    printf("Enter the dimensions of the Sparse Matrix 2 (of same order as 1st): ");
    scanf("%d %d", &r2, &c2);
    printf("Enter the number of Non-Zero elements: ");
    scanf("%d", &n2);
    struct Node *B[r2];
    for(int i=0; i<r2; i++){
        B[i] = NULL;
    }
    l=1;
    while(l <= n2){
        int i, j, key;
        printf("Enter the Row No., Column No. and Element No.%d: ", l);
        scanf("%d %d %d", &i, &j, &key);
        create(B, i, j, key);
        l++;
    }
    printf("---- SPARSE MATRIX 2 USING LINKED LISTS ---\n");
    display(B, r2, c2);
    printf("-----------------------------------------\n");

    struct Node *C[r1]; //Or r2 also can be used
    for(int i=0; i<r1; i++){
        C[i] = NULL;
    }
    add(r1, c1);
    printf("---- SPARSE MATRIX AFTER ADDING 1 & 2 USING LINKED LISTS ---\n");
    display(C, r2, c2);
    printf("-----------------------------------------\n");
    return 0;
}