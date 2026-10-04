public class ChildrenSum {

    static int sum = 0;

    static int findChildrenSum(Node P){
        if(P.left == null && P.right == null){return P.val;}
        if(P.left != null || P.right != null){
            sum = 0;
            if(P.left != null){sum += P.left.val;}
            if(P.right != null){sum += P.right.val;}
            
            if(sum < P.val){
                if(P.left != null){P.left.val = P.val;}
                if(P.right != null){P.right.val = P.val;}
            }
        }
        P.val = findChildrenSum(P.left) + findChildrenSum(P.right);
        return P.val;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        findChildrenSum(T.root);
        System.out.println("\n-->> Root.val is: " + T.root.val); System.out.println();
    }
}
