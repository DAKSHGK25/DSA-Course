import java.util.*;

class Tuple {
    Node P;
    int vertical;
    int level;

    Tuple(Node P, int x, int y){
        this.P = P;
        this.vertical = x; this.level = y;
    }
}

public class VerticalOrderTraversal {

    static void VerticalTraversal(Node P, ArrayList<Integer> arr){
        Tuple[] Q = new Tuple[25]; int f = -1, r = -1;
        TreeMap<Integer, TreeMap<Integer, ArrayList<Integer>>> map = new TreeMap<>();
        Q[++r] = new Tuple(P, 0, 0);
        map.putIfAbsent(Q[r].vertical, new TreeMap<>()); map.get(Q[r].vertical).putIfAbsent(Q[r].level, new ArrayList<>());
        map.get(Q[r].vertical).get(Q[r].level).add(Q[r].P.val);

        while(f<r){
            Tuple temp = Q[++f];

            if(temp.P.left != null){
                Q[++r] = new Tuple(temp.P.left, temp.vertical-1, temp.level+1);
                map.putIfAbsent(Q[r].vertical, new TreeMap<>()); map.get(Q[r].vertical).putIfAbsent(Q[r].level, new ArrayList<>());
                map.get(Q[r].vertical).get(Q[r].level).add(Q[r].P.val);
            }
            if(temp.P.right != null){
                Q[++r] = new Tuple(temp.P.right, temp.vertical+1, temp.level+1);
                map.putIfAbsent(Q[r].vertical, new TreeMap<>()); map.get(Q[r].vertical).putIfAbsent(Q[r].level, new ArrayList<>());
                map.get(Q[r].vertical).get(Q[r].level).add(Q[r].P.val);
            }
        }
        for(TreeMap<Integer, ArrayList<Integer>> temp : map.values()){
            for(ArrayList<Integer> x: temp.values()){
                Collections.sort(x);
                arr.addAll(x);
            }
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        ArrayList<Integer> arr = new ArrayList<>();
        VerticalTraversal(T.root, arr);
        System.out.println("\n-->> Vertical Order Traversal is: " + arr); System.out.println("\n");
    }
}