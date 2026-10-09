import java.util.*;

public class BSTIteratorBefore {

    Stack<Node> stk = new Stack<>();

    BSTIteratorBefore(Node root){
        pushAllB(root);
    }

    int before(){
        Node temp = stk.pop();
        pushAllB(temp.left);
        return temp.val;
    }

    boolean hasBefore(){
        return !stk.isEmpty();
    }

    void pushAllB(Node P){
        while(P != null){
            stk.push(P);
            P = P.right;
        }
    }

    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        BSTIteratorBefore client = new BSTIteratorBefore(T.root);System.out.println();
        System.out.print(client.before() + " ");
        System.out.print(client.before() + " ");
        System.out.print(client.hasBefore() + " ");
        System.out.print(client.before() + " ");
        System.out.print(client.hasBefore() + " ");
        System.out.print(client.before() + " ");
        System.out.print(client.before() + " ");
        System.out.print(client.hasBefore() + " ");System.out.println("\n");
    }
}
