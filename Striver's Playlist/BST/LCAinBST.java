public class LCAinBST {

    static Node LCA(Node P, int x, int y){
        if(P == null){return null;}
        if(P.val == x || P.val == y){return P;}

        Node ln = LCA(P.left, x, y), rn = LCA(P.right, x, y);

        if(ln == null && rn == null){return null;}
        if(ln == null ^ rn == null){
            return (ln==null)?rn:ln;
        }
        return P;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        int x = 5, y = 9;
        Node res = LCA(T.root, x, y);
        System.out.println("\n-->> LCA of " + x + " and " + y + " is: " + res.val); System.out.println();
    }
}