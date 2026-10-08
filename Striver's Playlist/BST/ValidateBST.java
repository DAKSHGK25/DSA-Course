public class ValidateBST {

    static boolean validate(Node P, int l, int h){
        if(P == null){return true;}

        boolean lv = validate(P.left, l, P.val), rv = validate(P.right, P.val, h);
        return (P.val > l && P.val < h) && lv && rv;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        boolean res = validate(T.root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        if(res){System.out.println("\n-->> It's a Valid BST\n");}
        else{System.out.println("\n-->> It's an Invalid BST\n");}
    }
}
