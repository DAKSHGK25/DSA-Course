public class LowestCommonAncestor {

    static Node LCA(Node P, int x, int y){
        if(P == null){return null;}
        if(P.val == x || P.val == y){return P;}

        Node lc = LCA(P.left, x, y), rc = LCA(P.right, x, y);
        if(lc == null && rc == null){return null;}
        else if(lc == null ^ rc == null){
            return (lc != null)?lc:rc;
        }
        return P;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        int x = 8, y = 7;
        Node P = LCA(T.root, x, y);
        System.out.println("\n-->> Lowest Common Ancestor of " + x + " & " + y + " is: " + P.val); System.out.println();
    }
}
