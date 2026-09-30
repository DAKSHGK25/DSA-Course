public class BoundaryTraversal {

    static int size = 0;

    static void leftBoundary(Node P, int[] arr){
        if(P != null && (P.left != null || P.right != null)){
            arr[size++] = P.val;
            if(P.left != null){leftBoundary(P.left, arr);}
            else{leftBoundary(P.right, arr);}
        }
    }

    static void leafNodes(Node P, int[] arr){
        if(P != null){
            if(P.left == null && P.right == null){arr[size++] = P.val;}
            leafNodes(P.left, arr);
            leafNodes(P.right, arr);
        }
    }

    static void rightBoundary(Node P, int[] arr){
        if(P != null && (P.left != null || P.right != null)){
            if(P.right != null){rightBoundary(P.right, arr);}
            else{rightBoundary(P.left, arr);}
            arr[size++] = P.val;
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();

        if(T.root == null){
            System.out.println("\n-->> The Tree is Empty!\n"); return;
        }

        if(T.root.left == null && T.root.right == null){
            System.out.printf("\n-->> Boundary Traversal: %d\n\n", T.root.val); return;
        }
        
        int[] boundary = new int[25];
        boundary[size++] = T.root.val;

        leftBoundary(T.root.left, boundary);
        leafNodes(T.root, boundary);
        rightBoundary(T.root.right, boundary);

        System.out.print("\n-->> Boundary Traversal: ");
        for(int i=0; i<size; i++){
            System.out.printf("%d ", boundary[i]);
        }
        System.out.println("\n");
    }
}
