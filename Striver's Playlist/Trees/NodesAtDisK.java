import java.util.*;

class RNode{
    int val;
    RNode lchild, rchild, parent;

    RNode(int val){
        this.val = val;
        this.lchild = this.rchild = this.parent = null;
    }
}

class RTree{
    RNode root = null;

    void create(){
        Scanner sc = new Scanner(System.in);
        int x;
        System.out.print("\n-->> Enter the root data: ");
        x = sc.nextInt();
        root = new RNode(x);

        RNode[] Q = new RNode[50];
        int f = -1, r = -1;
        Q[++r] = root;
        while(f<r){
            RNode temp = Q[++f];

            System.out.print("\n-->> Enter the data of left child of " + temp.val + ": ");
            x = sc.nextInt();
            if(x != -1){
                RNode l = new RNode(x);
                temp.lchild = l; l.parent = temp;
                Q[++r] = l;
            }

            System.out.print("-->> Enter the data of right child of " + temp.val + ": ");
            x = sc.nextInt();
            if(x != -1){
                RNode l = new RNode(x);
                temp.rchild = l; l.parent = temp;
                Q[++r] = l;
            }
        }
        System.out.println("\n-->> Tree created Successfully!");
    }
}

public class NodesAtDisK {

    static RNode findNode(RNode P, int target){
        if(P == null){return null;}
        if(P.val == target){return P;}

        RNode ln = findNode(P.lchild, target), rn = findNode(P.rchild, target);
        if(ln == null ^ rn == null){
            return (ln == null)?rn:ln;
        }
        return null;
    }

    static void getKNodes(RNode P, int k, int target, ArrayList<Integer> arr){
        int dis = 0, f = -1, r = -1;
        RNode[] Q = new RNode[50]; HashMap<Integer, Integer> visited = new HashMap<>();
        Q[++r] = findNode(P, target); visited.putIfAbsent(Q[r].val, 1); // The value is not required

        while(f < r && dis < k){
            int size = r-f;

            for(int i=0; i<size; i++){
                RNode curr = Q[++f];

                if(curr.parent != null && !visited.containsKey(curr.parent.val)){
                    Q[++r] = curr.parent;
                    visited.put(curr.parent.val, 1);
                }
                if(curr.lchild != null && !visited.containsKey(curr.lchild.val)){
                    Q[++r] = curr.lchild;
                    visited.put(curr.lchild.val, 1);
                }
                if(curr.rchild != null && !visited.containsKey(curr.rchild.val)){
                    Q[++r] = curr.rchild;
                    visited.put(curr.rchild.val, 1);
                }
            }
            dis++;
        }
        if(f < r){
            for(int i = f+1; i <= r; i++){
                arr.add(Q[i].val);
            }
        }
    }
    public static void main(String[] args){
        System.out.println("\n<<---- NODES AT A DISTANCE K ---->>\n");
        Scanner sc = new Scanner(System.in);
        RTree T = new RTree();
        T.create();

        ArrayList<Integer> arr = new ArrayList<>();
        System.out.print("\n-->> Enter the value of k: ");
        int k = sc.nextInt();
        System.out.print("\n-->> Enter the value of target: ");
        int target = sc.nextInt();
        getKNodes(T.root, k, target, arr);
        System.out.println("\n-->> Nodes at a distance " + k + " from Target node " + target + ": " + arr);System.out.println();

        sc.close();
    }
}