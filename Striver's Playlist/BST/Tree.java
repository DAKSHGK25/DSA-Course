import java.util.Scanner;

class Tree{

    Node root = null;

    void createTree(){
        Scanner sc = new Scanner(System.in);
        int x;
        System.out.print("\n-->> Enter the data of root: ");
        x = sc.nextInt();
        root = new Node(x);

        Node[] Q = new Node[25]; int f = -1, r = -1;
        Q[++r] = root;
        while(f<r){
            Node P = Q[++f];

            System.out.printf("\n-->> Enter the data of left child of %d: ", P.val);
            x = sc.nextInt();
            if(x != -1){
                Node temp = new Node(x);
                P.left = temp;
                Q[++r] = temp;
            }

            System.out.printf("-->> Enter the data of right child of %d: ", P.val);
            x = sc.nextInt();
            if(x != -1){
                Node temp = new Node(x);
                P.right = temp;
                Q[++r] = temp;
            }
        }
        System.out.println("\n-->> Tree created Successfully!");
        sc.close();
    }
}