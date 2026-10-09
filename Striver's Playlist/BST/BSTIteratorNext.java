import java.util.*;

public class BSTIteratorNext {

    Stack<Node> stk = new Stack<>();

    BSTIteratorNext(Node root){
        pushAll(root);
    }

    int next(){
        Node top = stk.pop();
        pushAll(top.right);
        return top.val;
    }

    boolean hasNext(){
        return !stk.isEmpty();
    }

    void pushAll(Node P){
        while(P != null){
            stk.push(P);
            P = P.left;
        }
    }

    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        BSTIteratorNext client = new BSTIteratorNext(T.root);System.out.println();
        System.out.print(client.next() + " ");
        System.out.print(client.next() + " ");
        System.out.print(client.hasNext() + " ");
        System.out.print(client.next() + " ");
        System.out.print(client.hasNext() + " ");
        System.out.print(client.next() + " ");
        System.out.print(client.hasNext() + " ");
        System.out.print(client.next() + " ");
        System.out.print(client.hasNext() + " ");System.out.println("\n");
    }
}
