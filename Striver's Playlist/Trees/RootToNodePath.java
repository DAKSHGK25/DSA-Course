import java.util.*;

public class RootToNodePath {

    static ArrayList<Integer> arr = new ArrayList<>();

    static boolean findPath(Node P, int key){
        if(P == null){return false;}

        arr.add(P.val);
        if(P.val == key){return true;}
        boolean lv = findPath(P.left, key), rv = findPath(P.right, key);

        if(!(lv || rv)){
            arr.remove(arr.size()-1);
        }
        return lv || rv;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        int key = 5;
        boolean res = findPath(T.root, key);
        if(res){
            System.out.println("\n-->> Path from Root to Node with key " + key + " is: " + arr);
        }
        else{
            System.out.println("\n-->> Key " + key + " is not Found in the Binary Tree");
        }
        System.out.println("\n");
    }
}