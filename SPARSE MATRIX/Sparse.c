//Validating a SPARSE MATRIX - if it contains >70% of Zeros
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
    printf("Enter the dimensions of the Sparse Matrix: ");
    scanf("%d %d", &S->m, &S->n);
    printf("Enter the number of Non-Zero elements: ");
    scanf("%d", &S->num);
    S->e = (struct Element *)malloc(S->num*sizeof(struct Element));
    printf("Enter the row no., column no. and element: ");
    for(int l=0; l<S->num; l++){
        scanf("%d %d %d", &S->e[l].i, &S->e[l].j, &S->e[l].x);
    }
}

void display(struct Sparse S){
    int k =0;
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

int main(){
    struct Sparse S;
    create(&S);
    printf("Sparse Matrix -->\n");
    printf("-----------------\n");
    display(S);
    printf("-----------------\n");
    if((1 - (S.num/(float)(S.m*S.n))) > 0.7){
        printf("It's a SPARSE MATRIX (>70 percentage Zeros)");
    }
    else{
        printf("It's not a SPARSE MATRIX (<70 percentage Zeros)");
    }
    return 0;
}