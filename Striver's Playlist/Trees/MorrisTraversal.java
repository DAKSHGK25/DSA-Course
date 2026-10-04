public class MorrisTraversal {
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();

        System.out.print("\n-->> InOrder Traversal as per MORRIS Traversal: ");
        Node curr = T.root;
        while(curr != null){
            if(curr.left == null){      // No left subtree exists
                // Print the node.val and then move on to the right subtree
                System.out.printf("%d ", curr.val);
                curr = curr.right;
            }
            else{       // There exists a left subtree
                // Move to the rightmost node of the left subtree:
                // 1. If the thread to the root exists, then remove it and move on to the right subtree
                // 2. If the thread doesn't exist, establish a thread and move to the left subtree
                Node prev = curr.left;
                while(prev.right != null && prev.right != curr){
                    prev = prev.right;
                }

                if(prev.right == null){     // Thread has not been established yet
                    prev.right = curr;
                    curr = curr.left;
                }
                else{   // Thread has already been established
                    prev.right = null;
                    System.out.printf("%d ", curr.val);
                    curr = curr.right;
                }
            }
        }
        System.out.println("\n");
    }
}
