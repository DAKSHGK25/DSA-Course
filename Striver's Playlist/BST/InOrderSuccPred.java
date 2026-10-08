public class InOrderSuccPred {
    static Node succ = null, pred = null;
    static void InSuccessor(Node P, int key){
        if(P == null){return;}
        if(P.val < key){
            InSuccessor(P.right, key);
        }
        else{succ = P; return;}
    }

    static void InPredecessor(Node P, int key){
        if(P == null){return;}
        if(P.val > key){
            InPredecessor(P.left, key);
        }
        else{pred = P;}
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        InSuccessor(T.root, 8); InPredecessor(T.root, 3);
        if(succ != null){System.out.println("\n-->> Inorder Successor is: " + succ.val);}
        else{System.out.println("\n-->> InOrder Successor doesn't exist!");}
        if(pred != null){System.out.println("\n-->> Inorder Predecessor is: " + pred.val);}
        else{System.out.println("\n-->> InOrder Predecessor doesn't exist!");}
        System.out.println();
    }
}
