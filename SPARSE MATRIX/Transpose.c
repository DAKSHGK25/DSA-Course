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

void transpose(struct Sparse *S){
    int temp = S->m;
    S->m = S->n;
    S->n = temp;
    for(int l=0; l<S->num; l++){
        temp = S->e[l].i;
        S->e[l].i = S->e[l].j;
        S->e[l].j = temp;
    }

    //Sorting the Sub-Arrays representing elements with respect to Row and Column number
    //SELECTION SORT
    for(int l=0; l<S->num; l++){
        int pos = l;
        for(int k=l+1; k<S->num; k++){
            if(S->e[pos].i > S->e[k].i){
                pos = k;
            }
            else if(S->e[pos].i == S->e[k].i){
                if(S->e[pos].j > S->e[k].j){
                    pos = k;
                }
            }
        }
        if(pos!=l){
            struct Element temporary = S->e[l];
            S->e[l] = S->e[pos];
            S->e[pos] = temporary;
        }
    }
}

int main(){
    struct Sparse S;
    create(&S);
    printf("Sparse Matrix -->\n");
    printf("-----------------\n");
    display(S);
    printf("-----------------\n");
    printf("Transpose of Sparse Matrix -->\n");
    transpose(&S);
    display(S);
    printf("-----------------\n");
    return 0;
}