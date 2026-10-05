public class FlattenBTasLL {

    static Node prev = null;

    static void flattenBTRec(Node P){
        if(P == null){return;}

        flattenBTRec(P.right);
        flattenBTRec(P.left);

        P.right = prev;
        P.left = null;
        prev = P;
    }

    static void flattenBTStack(Node P){
        if(P == null){return;}
        Node[] stk = new Node[25]; int top = -1;
        stk[++top] = P;
        while(top != -1){
            Node curr = stk[top--];

            if(curr.right != null){
                stk[++top] = curr.right;
            }
            if(curr.left != null){
                stk[++top] = curr.left;
            }
            if(top != -1){
                curr.right = stk[top];
            }
            curr.left = null;
        }
    }

    static void flattenBTMorris(Node P){
        if(P == null){return;}

        Node curr = P;
        while(curr != null){
            if(curr.left == null){
                // If the left subtree doesn't exist, then move right
                curr = curr.right;
            }
            else{
                // if the left subtree exists then we mark 2 pointers: 'prev' and 'next'
                Node prev = curr.left, next = curr.right;
                while(prev.right != null && prev.right != curr){
                    prev = prev.right;
                }

                if(prev.right == null){
                    // The thread doesn't exist, so need to be established and then move left
                    prev.right = curr;
                    curr = curr.left;
                }
                else{
                    // The thread already exists, remove the thread along with some pointer manipulations and then move right
                    prev.right = next;
                    curr.right = curr.left;
                    curr.left = null;
                    // curr = curr.right; // or
                    curr = next;
                }
            }
        }
    }

    static void printSkew(Node P){
        if(P != null){
            System.out.printf("%d ", P.val);
            printSkew(P.right);
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();

        System.out.print("\n-->> Skew before Flattening: "); printSkew(T.root); System.out.println();
        // flattenBTRec(T.root);
        // flattenBTStack(T.root);
        flattenBTMorris(T.root);
        System.out.print("\n-->> Skew after Flattening: "); printSkew(T.root); System.out.println("\n");
    }
}
