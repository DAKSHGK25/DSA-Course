#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *a;
    int size;
};

void set(struct Matrix *M, int i, int j, int x){
    if(i==j){
        M->a[i] = x;
    }
}

int get(struct Matrix M, int i, int j){
    if(i==j){return M.a[i];}
    else{return 0;}
}

void display(struct Matrix M){
    for(int i=0; i<M.size; i++){
        for(int j=0; j<M.size; j++){
            if(i==j){
                printf("%d ", M.a[i]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    struct Matrix M;
    printf("Enter the dimension of 2D Array: ");
    scanf("%d", &M.size);
    M.a = (int *)malloc(sizeof(int)*M.size);
    printf("Enter the Diagonal elements: ");
    for(int i=0; i<M.size; i++){
        scanf("%d", &M.a[i]);
        //set(&M, i, i, M.a[i]);
    }
    int r, c;
    printf("Enter row index: ");
    scanf("%d", &r);
    printf("Enter column index: ");
    scanf("%d", &c);
    printf("Element at row %d and column %d is: %d\n", r, c, get(M, r, c));
    printf("Matrix -->\n");
    display(M);
    return 0;
}