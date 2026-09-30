public class MaxDepth {

    static int maxDepth(Node P){
        if(P == null){return 0;}
        int x = maxDepth(P.left), y = maxDepth(P.right);
        return (x>y)?x+1:y+1;
    }

    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        System.out.println("\n-->> Maximum Depth of the Binary Tree is: " + maxDepth(T.root));
        System.out.println();
    }
}
