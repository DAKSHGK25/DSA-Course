#include <stdio.h>
#include <stdlib.h>

struct Tree{
    struct Tree *lchild;
    int data;
    struct Tree *rchild;
}*root = NULL;

struct Tree * createTree(struct Tree *T, int *postStart, int inStart, int inEnd, int *post, int *in){
    if(inStart > inEnd){return NULL;}

    int index = -1;
    for(int i=inStart; i<=inEnd; i++){
        if(post[*postStart] == in[i]){
            index = i; break;
        }
    }

    T = (struct Tree *)malloc(sizeof(struct Tree));
    T->data = post[*postStart]; (*postStart)--;
    T->lchild = T->rchild = NULL;

    T->rchild = createTree(T->rchild, postStart, index+1, inEnd, post, in);
    T->lchild = createTree(T->lchild, postStart, inStart, index-1, post, in);

    return T;
}

void inOrder(struct Tree *T){
    if(T){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

int main(){
    int n;
    printf("\n-->> Enter the no. of nodes in the Tree: "); scanf("%d", &n);
    int post[n], in[n];
    printf("Enter the PostOrder traversal of the Tree: ");
    for(int i=0; i<n; i++){
        scanf("%d", post+i);
    }
    printf("Enter the InOrder traversal of the Tree: ");
    for(int i=0; i<n; i++){
        scanf("%d", in+i);
    }
    int postStart = n-1, postEnd = 0, inStart = 0, inEnd = n-1;
    root = createTree(root, &postStart, inStart, inEnd, post, in);
    printf("\n-->> TREE elements (following Inorder Traversal) --> ");
    inOrder(root);
    return 0;
}