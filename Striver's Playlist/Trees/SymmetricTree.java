public class SymmetricTree {

    static boolean checkSymmetry(Node P, Node Q){
        if(P != null ^ Q != null){return false;}
        if(P == null && Q == null){return true;}
        return (P.val == Q.val) && checkSymmetry(P.left, Q.right) && checkSymmetry(P.right, Q.left);
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();

        if(T.root == null){System.out.println("\n-->> Tree is EMPTY!\n"); return;}
        boolean res = checkSymmetry(T.root.left, T.root.right);
        if(res){
            System.out.println("\n-->> Tree is SYMMETRIC!\n"); return;
        }
        System.out.println("\n-->> Tree is NOT SYMMETRIC!\n");
    }
}
