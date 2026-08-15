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
    for(int l=0; l<S->num; l++){
        scanf("%d %d %d", &S->e[l].i, &S->e[l].j, &S->e[l].x);
    }
}

void display(struct Sparse S){
    int k = 0;
    for(int i=1; i<=S.m; i++){
        for(int j=1; j<=S.n; j++){
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

void subtract(struct Sparse A, struct Sparse B, struct Sparse *C){
    if(A.m!=B.m || A.n!=B.n){
        printf("Matrices cannot be subtracted!");
        return;
    }
    C->m = A.m; C->n = A.n; C->num = A.num+B.num;
    C->e = (struct Element *)malloc(C->num*sizeof(struct Element));
    int k = 0, l = 0, g = 0;    //k-A, l-B, g-C
    while(k < A.num || l < B.num){
        if(A.e[k].i == B.e[l].i && A.e[k].j == B.e[l].j){
            C->e[g].i = A.e[k].i;
            C->e[g].j = A.e[k].j;
            C->e[g].x = A.e[k].x-B.e[l].x;
            k++; l++; g++;
        }
        else if(A.e[k].i == B.e[l].i && A.e[k].j != B.e[l].j){
            if(A.e[k].j > B.e[l].j){
                C->e[g] = B.e[l];
                l++; g++;
            }
            else{
                C->e[g] = A.e[k];
                k++; g++;
            }
        }
        else if(A.e[k].i != B.e[l].i){
            if(A.e[k].i > B.e[l].i){
                C->e[g] = B.e[l];
                l++; g++;
            }
            else{
                C->e[g] = A.e[k];
                k++; g++;
            }
        }
    }
    C->num = g;
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
    subtract(A, B, &C);
    printf("Sparse Matrix-C (DIFFERENCE): \n");
    display(C);
    return 0;
}