public class KthSmallestEle {

    static int count = 0, ele = -1;

    static void InOrder(Node P, int k){
        if(P != null){
            InOrder(P.left, k);
            count++;
            if(count == k){ele = P.val; return;}
            InOrder(P.right, k);
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        InOrder(T.root, 5);
        System.out.println("\n-->> Kth(5) Smallest element is: " + ele);
        System.out.println("\n");
    }
}