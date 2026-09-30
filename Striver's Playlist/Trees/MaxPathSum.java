public class MaxPathSum {

    static int maxSum = 0;

    static int PathSum(Node P){
        if(P == null){return 0;}

        int lsum = Math.max(0, PathSum(P.left)), rsum = Math.max(0, PathSum(P.right));
        maxSum = Math.max(maxSum, lsum+rsum+P.val);

        return P.val+Math.max(0,Math.max(lsum, rsum));
    }
    public static void main(String[] args){
        maxSum = 0;
        Tree T = new Tree();
        T.createTree();
        PathSum(T.root);
        System.out.println("\n-->> Maximum Path Sum is: " + maxSum); System.out.println();
    }
}
