import java.util.*;

class Tuple {
    Node P;
    int vertical;

    Tuple(Node P, int x){
        this.P = P;
        this.vertical = x;
    }
}

public class TopView {

    static void getTopView(Node P, ArrayList<Integer> arr){
        TreeMap<Integer, Node> map = new TreeMap<>();
        Tuple[] Q = new Tuple[25]; int f = -1, r = -1;
        Q[++r] = new Tuple(P, 0);
        map.putIfAbsent(Q[r].vertical, Q[r].P);
        while(f<r){
            Tuple temp = Q[++f];

            if(temp.P.left != null){
                Q[++r] = new Tuple(temp.P.left, temp.vertical-1);
                map.putIfAbsent(Q[r].vertical, Q[r].P);
            }

            if(temp.P.right != null){
                Q[++r] = new Tuple(temp.P.right, temp.vertical+1);
                map.putIfAbsent(Q[r].vertical, Q[r].P);
            }
        }

        for(Node x: map.values()){
            arr.add(x.val);
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        ArrayList<Integer> arr = new ArrayList<>();
        getTopView(T.root, arr);
        System.out.println("\n-->> Top View of the Binary Tree is: " + arr); System.out.println("\n");
    }
}