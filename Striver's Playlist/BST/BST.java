import java.util.*;

public class BST {

    static int ceil(Node P, int key){       // Ceil - Smallest value >= key
        Node T = P; int ceilVal = -1;
        while(T != null){
            if(T.val == key){ceilVal = key; break;}
            else if(T.val > key){ceilVal = T.val; T = T.left;}
            else{T = T.right;}
        }
        return ceilVal;
    }

    static int floor(Node P, int key){
        Node T = P; int floorVal = -1;
        while(T != null){
            if(T.val == key){floorVal = key; break;}
            else if(T.val > key){T = T.left;}
            else{
                floorVal = T.val; T = T.right;
            }
        }
        return floorVal;
    }

    static void insertBST(Node P, int key){
        Node curr = P, prev = null;
        while(curr != null){
            prev = curr;
            if(curr.val == key){System.out.println("\n-->> Key already exists in the BST"); return;}
            else if(curr.val < key){
                curr = curr.right;
            }
            else{
                curr = curr.left;
            }
        }
        Node R = new Node(key);
        if(prev.val < key){prev.right = R; return;}
        prev.left = R;
    }

    static Node insertRec(Node P, int key){
        if(P == null){
            Node temp = new Node(key);
            return temp;
        }

        if(P.val < key){
            P.right = insertRec(P.right, key);
        }
        else if(P.val > key){
            P.left = insertRec(P.left, key);
        }
        return P;
    }

    // static Node delete(Node P, int key){

    // }

    static void InOrder(Node P){
        if(P != null){
            InOrder(P.left);
            System.out.printf("%d ", P.val);
            InOrder(P.right);
        }
    }

    static Node searchBST(Node P, int key){
        if(P == null){return null;}

        Node ln = null, rn = null;
        if(P.val == key){return P;}
        else if(P.val < key){
            rn = searchBST(P.right, key);
        }
        else{
            ln = searchBST(P.left, key);
        }
        if(ln == null && rn == null){return null;}
        return (ln == null)?rn:ln;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        int target = 10;
        Node P = searchBST(T.root, target);

        if(P == null){System.out.println("\n-->> Target " + target + " is not found in the BST!");}
        else{System.out.println("\n-->> Target " + target + " is found in the BST!");}

        System.out.println("\n-->> Ceil of 5 is: " + ceil(T.root, 5));
        System.out.println("\n-->> Floor of 2 is: " + floor(T.root, 2));
        System.out.print("\n-->> InOrder Traversal: "); InOrder(T.root);

        // insertBST(T.root, 5);
        T.root = insertRec(T.root, 5);
        System.out.print("\n-->> InOrder Traversal: "); InOrder(T.root);

        System.out.println("\n");
    }
}
