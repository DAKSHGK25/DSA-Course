public class BSTfromPreOrder {
    static int index = 0;
    static Node BSTPre(Node P, int[] pre, int high){
        if(index == pre.length){return null;}
        else{
            if(pre[index] < high){
                P = new Node(pre[index++]);
                P.left = BSTPre(P.left, pre, P.val);
                P.right = BSTPre(P.right, pre, high);
            }
        }
        return P;
    }

    static void inOrder(Node P){
        if(P!=null){
            inOrder(P.left);
            System.out.printf("%d ", P.val);
            inOrder(P.right);
        }
    }
    public static void main(String[] args){
        int[] pre = {50, 30, 20, 10, 25, 40, 35, 45, 70, 60, 55, 65, 80, 75, 90};
        Node root = null;
        root = BSTPre(root, pre, Integer.MAX_VALUE);
        System.out.print("\n-->> BST from InOrder: "); inOrder(root); System.out.println("\n");
    }
}
