import java.util.*;

class Tuple {
    Node P;
    int vertical;

    Tuple(Node P, int x){
        this.P = P;
        this.vertical = x;
    }
}

public class BottomView {

    static void getBottomView(Node P, ArrayList<Integer> arr){
        Tuple[] Q = new Tuple[25]; int f = -1, r = -1;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        Q[++r] = new Tuple(P, 0);
        map.put(Q[r].vertical, Q[r].P.val);
        while(f<r){
            Tuple temp = Q[++f];

            if(temp.P.left != null){
                Q[++r] = new Tuple(temp.P.left, temp.vertical-1);
                map.put(Q[r].vertical, Q[r].P.val);
            }

            if(temp.P.right != null){
                Q[++r] = new Tuple(temp.P.right, temp.vertical+1);
                map.put(Q[r].vertical, Q[r].P.val);
            }
        }

        for(Integer val: map.values()){
            arr.add(val);
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        ArrayList<Integer> arr = new ArrayList<>();
        getBottomView(T.root, arr);
        System.out.println("\n-->> Bottom View of the Binary Tree is: " + arr); System.out.println("\n");
    }
}