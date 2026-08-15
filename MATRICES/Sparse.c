#include <stdio.h>
#include <stdlib.h>

struct Element{
    int i;  //Row No.
    int j;  //Column No.
    int x;  //Element
};

struct Sparse{
    int m;  //Number of Rows
    int n;  //Number of Columns
    int num;    //Number of Non-Zero elements
    struct Element *e;  //Pointer to store Non-Zero elements dynamically
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
    int k = 0;  //Non Zero elements
    for(int i=0; i<S.m; i++){
        for(int j=0; j<S.n; j++){
            if(i+1 == S.e[k].i && j+1 == S.e[k].j){
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
    display(S);
    return 0;
}