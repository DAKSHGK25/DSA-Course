public class KthLargestEle {
    static int count = 0, ele = -1;

    static void InOrder(Node P, int k){
        if(P != null){
            InOrder(P.right, k);
            count++;
            if(count == k){ele = P.val; return;}
            InOrder(P.left, k);
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        InOrder(T.root, 5);
        System.out.println("\n-->> Kth(5) Largest element is: " + ele);
        System.out.println("\n");
    }
}
