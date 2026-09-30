public class CheckBalance {

    static int height(Node P){
        if(P == null){return 0;}
        int x = height(P.left), y = height(P.right);
        if(x == -1 || y == -1){return -1;}
        if(Math.abs(x-y) > 1){return -1;}   // Imbalanced
        return (x>y)?x+1:y+1;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        int h = height(T.root);
        if(h >= 0){
            System.out.println("\n-->> The Binary Tree is Balanced!");;
        }
        else{
            System.out.println("\n-->> The Binary Tree is Imbalanced!");
        }
        System.out.println();
    }
}
