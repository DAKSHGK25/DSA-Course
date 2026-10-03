import java.util.ArrayList;

public class LeftView {

    static ArrayList<Integer> arr = new ArrayList<>();

    static void getLeftView(Node P, int level){ // root -> left -> right
        if(P == null){return;}

        if(arr.size() == level){arr.add(P.val);}
        getLeftView(P.left, level+1);
        getLeftView(P.right, level+1);
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        getLeftView(T.root, 0);
        System.out.println("\n-->> Left View of the Binary Tree is: " + arr); System.out.println("\n");
    }
}
