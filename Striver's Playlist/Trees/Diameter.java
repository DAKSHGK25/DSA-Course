// Diameter of a Binary Tree --> Longest path between any 2 nodes.. Need not have to pass through the root

public class Diameter {

    static int height(Node P){
        if(P == null){return 0;}
        int x = height(P.left), y = height(P.right);
        return (x>y)?x+1:y+1;
    }

    static int maxDia = 0;

    // Naive (Brute Force) Solution
    static void findDiameter(Node P){
        if(P == null){return;}

        int lh = height(P.left), rh = height(P.right);
        maxDia = Math.max(maxDia, rh+lh);

        findDiameter(P.left); findDiameter(P.right);
    }

    // Optimised Solution -->> Calculate max Diameter while calculating the height itself
    static int findDiameterOptimised(Node P){
        if(P == null){return 0;}

        int lh = findDiameterOptimised(P.left), rh = findDiameterOptimised(P.right);

        maxDia = Math.max(maxDia, rh+lh);
        return (lh>rh)?lh+1:rh+1;
    }

    public static void main(String[] args){
        maxDia = 0;
        Tree T = new Tree();
        T.createTree(); findDiameterOptimised(T.root);
        System.out.println("\n-->> Diameter of the Binary Tree is: " + maxDia);
        System.out.println();
    }
}
