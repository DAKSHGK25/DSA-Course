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

public class MinTimeBurnBT {

    static RNode findNode(RNode P, int target){
        if(P == null){return null;}
        if(P.val == target){return P;}

        RNode ln = findNode(P.lchild, target), rn = findNode(P.rchild, target);
        if(ln == null ^ rn == null){
            return (ln == null)?rn:ln;
        }
        return null;
    }

    static int findTimetoBurn(RNode P, int target){
        if(P == null){return 0;}

        int f = -1, r = -1, time = 0;
        RNode[] Q = new RNode[50]; HashMap<Integer, Integer> map = new HashMap<>();
        Q[++r] = findNode(P, target); map.put(Q[r].val, 1);
        while(f < r){
            int size = r-f;
            for(int i=0; i<size; i++){
                RNode curr = Q[++f];

                if(curr.parent != null && !map.containsKey(curr.parent.val)){
                    Q[++r] = curr.parent;
                    map.put(curr.parent.val, 1);
                }
                if(curr.lchild != null && !map.containsKey(curr.lchild.val)){
                    Q[++r] = curr.lchild;
                    map.put(curr.lchild.val, 1);
                }
                if(curr.rchild != null && !map.containsKey(curr.rchild.val)){
                    Q[++r] = curr.rchild;
                    map.put(curr.rchild.val, 1);
                }
            }
            if(f<r){time++;}
        }
        return time;
    }
    public static void main(String[] args){
        System.out.println("\n<<---- MIN TIME TO BURN A BINARY TREE ---->>\n");
        Scanner sc = new Scanner(System.in);
        RTree T = new RTree();
        T.create();

        int target;
        System.out.print("\n-->> Enter the Target value: "); target = sc.nextInt();
        int time = findTimetoBurn(T.root, target);
        System.out.println("\n-->> Minimum Time to Burn the Binary Tree: " + time); System.out.println();

        sc.close();
    }
}