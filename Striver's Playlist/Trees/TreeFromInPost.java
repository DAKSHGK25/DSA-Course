class Node {

    int val;
    Node left, right;

    Node(int val){
        this.val = val;
        this.left = this.right = null;
    }
}

public class TreeFromInPost {
    
    static int post = 0;

    static Node createTreeFromInPost(Node P, int[] inOrder, int[] postOrder, int inStart, int inEnd){
        if(inStart > inEnd){return null;}

        int index = 0;
        for(int i=inStart; i<=inEnd; i++){
            if(inOrder[i] == postOrder[post]){
                index = i; break;
            }
        }

        P = new Node(postOrder[post--]);

        // First build the right subtree and then build the left
        P.right = createTreeFromInPost(P.right, inOrder, postOrder, index+1, inEnd);
        P.left = createTreeFromInPost(P.left, inOrder, postOrder, inStart, index-1);

        return P;
    }

    static void PreOrder(Node P){
        if(P != null){
            System.out.printf("%d ", P.val);
            PreOrder(P.left);
            PreOrder(P.right);
        }
    }
    public static void main(String[] args){
        int[] inOrder = {7, 3, 8, 1, 9, 4, 10, 2, 5};
        int[] postOrder = {7, 8, 3, 9, 10, 4, 5, 2, 1};
        post = postOrder.length-1;

        Node root = null;
        root = createTreeFromInPost(root, inOrder, postOrder, 0, inOrder.length-1);

        System.out.print("\n-->> PreOrder Traversal of the Tree created: "); PreOrder(root); System.out.println("\n");
    }
}