class Tuple {
    Node P;
    int index;

    Tuple(Node P, int i){
        this.P = P;
        this.index = i;
    }
}

public class MaxWidth {

    static int findMaxWidth(Node P){
        Tuple[] Q = new Tuple[50]; int f = -1, r = -1;
        Q[++r] = new Tuple(P, 1);   // 1-based indexing
        int Width = -1;
        while(f<r){
            int minIndex = Q[f+1].index, maxIndex = Q[r].index;
            if(Width < (maxIndex-minIndex+1)){Width = maxIndex-minIndex+1;}

            int l = r-f;
            for(int i=0; i<l; i++){
                Tuple temp = Q[++f];

                if(temp.P.left != null){
                    Q[++r] = new Tuple(temp.P.left, (temp.index*2)-(minIndex*2));
                }
                if(temp.P.right != null){
                    Q[++r] = new Tuple(temp.P.right, (temp.index*2+1)-(minIndex*2));
                }
            }
        }
        return Width;
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        int MWidth = findMaxWidth(T.root);
        System.out.println("\n-->> Maximum Width of the Binary Tree is: " + MWidth); System.out.println();
    }
}
