#include <stdio.h>

void input(int r, int c, int a[r][c]){
    int (*p)[c] = a;
    printf("Enter the Array elements: ");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &(*(*(p+i)+j)));
        }
    }
}

void display(int r, int c, int a[r][c]){
    int (*p)[c] = a;
    printf("Array -->\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", *(*(p+i)+j));
        }
        printf("\n");
    }
}

int main(){
    int r, c;
    printf("Enter the number of Rows and Columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    input(r, c, a);
    display(r, c, a);
    return 0;
}