#include <stdio.h>
#include <stdlib.h>

struct Tree{
    struct Tree *lchild;
    int data;
    struct Tree *rchild;
}*root = NULL;

struct Tree * createTree(struct Tree *T, int *preStart, int inStart, int inEnd, int *pre, int *in){
    if(inStart > inEnd){return NULL;}
    int index = -1;
    for(int i=inStart; i<=inEnd; i++){
        if(pre[*preStart] == in[i]){
            index = i;break;
        }
    }

    T = (struct Tree *)malloc(sizeof(struct Tree));
    T->data = pre[*preStart]; (*preStart)++;
    T->lchild = T->rchild = NULL;

    T->lchild = createTree(T->lchild, preStart, inStart, index-1, pre, in);
    T->rchild = createTree(T->rchild, preStart, index+1, inEnd, pre, in);
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
    int pre[n], in[n];
    printf("Enter the PreOrder traversal of the Tree: ");
    for(int i=0; i<n; i++){
        scanf("%d", pre+i);
    }
    printf("Enter the InOrder traversal of the Tree: ");
    for(int i=0; i<n; i++){
        scanf("%d", in+i);
    }
    int preStart = 0, preEnd = n-1, inStart = 0, inEnd = n-1;
    root = createTree(root, &preStart, inStart, inEnd, pre, in);
    printf("\n-->> TREE elements (following Inorder Traversal) --> ");
    inOrder(root);
    return 0;
}