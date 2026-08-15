#include <stdio.h>
#include <stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *S){
    printf("Enter the dimensions: ");
    scanf("%d %d", &S->m, &S->n);
    printf("Enter the count of Non-Zero elements: ");
    scanf("%d", &S->num);
    S->e = (struct Element *)malloc(S->num*sizeof(struct Element));
    printf("Enter the Non-Zero elements (row, column, element): ");
    for(int i=0; i<S->num; i++){
        scanf("%d %d %d", &S->e[i].i, &S->e[i].j, &S->e[i].x);
    }
}

void display(struct Sparse S){
    int k = 0;
    for (int i = 1; i <= S.m; i++)
    {
        for(int j = 1; j <= S.n; j++){
            if(i == S.e[k].i && j == S.e[k].j){
                printf("%d ", S.e[k].x);
                k++;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    
}

void add(struct Sparse A, struct Sparse B, struct Sparse *C){
    if(A.m!=B.m || A.n!=B.n){
        printf("Matrices cannot be added!");
        return;
    }

    C->m = A.m; C->n = A.n; C->num = A.num+B.num;
    C->e = (struct Element *)malloc(C->num*(sizeof(struct Element)));
    int k = 0, g = 0; int l = 0;
    while(k < A.num || g < B.num){
        if(A.e[k].i == B.e[g].i && A.e[k].j == B.e[g].j){
            C->e[l].i = A.e[k].i;
            C->e[l].j = A.e[k].j;
            C->e[l].x = A.e[k].x+B.e[g].x;
            k++; g++; l++;
        }
        else if(A.e[k].i == B.e[g].i && A.e[k].j != B.e[g].j){
            if(A.e[k].j > B.e[g].j){
                // C->e[l].i = B.e[g].i;
                // C->e[l].j = B.e[g].j;
                // C->e[l].x = B.e[g].x;
                C->e[l] = B.e[g];
                l++; g++;
            }
            else{
                // C->e[l].i = A.e[k].i;
                // C->e[l].j = A.e[k].j;
                // C->e[l].x = A.e[k].x;
                C->e[l] = A.e[k];
                l++; k++;
            }
        }
        else if(A.e[k].i != B.e[g].i){
            if(A.e[k].i > B.e[g].i){
                // C->e[l].i = B.e[g].i;
                // C->e[l].j = B.e[g].j;
                // C->e[l].x = B.e[g].x;
                C->e[l] = B.e[g];
                l++; g++;
            }
            else{
                // C->e[l].i = A.e[k].i;
                // C->e[l].j = A.e[k].j;
                // C->e[l].x = A.e[k].x;
                C->e[l] = A.e[k];
                l++; k++;
            }
        }
    }
    C->num = l;
}

int main(){
    struct Sparse A, B, C;
    printf("For Sparse Matrix-A: \n");
    create(&A);
    printf("Sparse Matrix-A -->\n");
    display(A);
    printf("For Sparse Matrix-B: \n");
    create(&B);
    printf("Sparse Matrix-B -->\n");
    display(B);
    add(A, B, &C);
    printf("Sparse Matrix-C (SUM): \n");
    display(C);
    return 0;
}