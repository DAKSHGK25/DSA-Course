class Node{

    int val;
    Node left, right;

    Node(int val){
        this.val = val;
        this.left = this.right = null;
    }
}

public class TreeFromInPre {

    static int pre = 0;

    static Node createTreeFromInPre(Node P, int[] inOrder, int[] preOrder, int inStart, int inEnd){
        if(inStart > inEnd){
            return null;
        }

        int index = 0;
        for(int i=inStart; i<=inEnd; i++){
            if(inOrder[i] == preOrder[pre]){
                index = i; break;
            }
        }

        P = new Node(preOrder[pre++]);

        // First build the left subtree and then build the right
        P.left = createTreeFromInPre(P.left, inOrder, preOrder, inStart, index-1);
        P.right = createTreeFromInPre(P.right, inOrder, preOrder, index+1, inEnd);

        return P;
    }

    static void PostOrder(Node P){
        if(P != null){
            PostOrder(P.left);
            PostOrder(P.right);
            System.out.printf("%d ", P.val);
        }
    }
    public static void main(String[] args){
        pre = 0;
        int[] inOrder = {7, 3, 8, 1, 9, 4, 10, 2, 5};
        int[] preOrder = {1, 3, 7, 8, 2, 4, 9, 10, 5};

        Node root = null;
        root = createTreeFromInPre(root, inOrder, preOrder, 0, inOrder.length-1);

        System.out.print("\n-->> PostOrder Traversal of the Tree created: "); PostOrder(root); System.out.println("\n");
    }
}