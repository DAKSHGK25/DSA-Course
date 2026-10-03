import java.util.*;

public class RigthView {

    static ArrayList<Integer> arr = new ArrayList<>();

    static void getRightView(Node P, int level){    // root -> right -> left
        if(P == null){return;}
        if(arr.size() == level){arr.add(P.val);}
        getRightView(P.right, level+1);
        getRightView(P.left, level+1);
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        getRightView(T.root, 0);
        System.out.println("\n-->> Right View of the Binary Tree is: " + arr); System.out.println("\n");
    }
}
