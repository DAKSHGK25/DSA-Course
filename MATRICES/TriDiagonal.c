#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *a;
    int size;
};

void set(struct Matrix *M, int i, int j, int x){
    int loc = 0;
    if(abs(i-j) <= 1){
        if(i-j == 1){   //Lower Diagonal
            loc = i-1;
            M->a[loc] = x;
        }
        else if(i-j == -1){ //Upper Diagonal
            loc = (2*M->size)-1+i;
            M->a[loc] = x;
        }
        else{   //Main Diagonal
            loc = M->size-1+i;
            M->a[loc] = x;
        }
    }
}

int get(struct Matrix M, int i, int j){
    int loc = 0;
    if(abs(i-j) <= 1){
        if(i-j == 1){   //Lower Diagonal
            loc = i-1;
            return M.a[loc];
        }
        else if(i-j == -1){ //Upper Diagonal
            loc = (2*M.size)-1+i;
            return M.a[loc];
        }
        else{   //Main Diagonal
            loc = M.size-1+i;
            return M.a[loc];
        }
    }
    else{
        return 0;
    }
}

void display(struct Matrix M){
    int loc = 0;
    for(int i=0; i<M.size; i++){
        for(int j=0; j<M.size; j++){
            if(abs(i-j) <= 1){
                if(i-j == 1){   //Lower Diagonal
                    loc = i-1;
                }
                else if(i-j == -1){ //Upper Diagonal
                    loc = (2*M.size)+i-1;
                }
                else{
                    loc = M.size+i-1;
                }
                printf("%d ", M.a[loc]);
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
    M.a = (int *)malloc(((3*M.size)-2)*sizeof(int));
    int x;
    printf("Enter %d elements for the TriDiagonal Matrix : ", M.size*M.size);
    for(int i=0; i<M.size; i++){
        for(int j=0; j<M.size; j++){
            scanf("%d", &x);
            set(&M, i, j, x);
        }
    }
    int r, c;
    printf("Enter row index: ");
    scanf("%d", &r);
    printf("Enter column index: ");
    scanf("%d", &c);
    printf("Element at row %d and column %d is: %d\n", r, c, get(M, r, c));
    printf("TriDiagonal Matrix -->\n");
    display(M);
    return 0;
}