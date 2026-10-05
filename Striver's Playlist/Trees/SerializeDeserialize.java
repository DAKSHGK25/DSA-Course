import java.util.*;

public class SerializeDeserialize {

    static String serialize(Node P){
        if(P == null){return "";}
        StringBuilder str = new StringBuilder();
        ArrayDeque<Node> Q = new ArrayDeque<>();
        Q.offerLast(P);
        str.append(Integer.toString(P.val));
        str.append(',');
        while(!Q.isEmpty()){
            Node temp = Q.pollFirst();
            
            if(temp.left != null){
                Q.offerLast(temp.left);
                str.append(Integer.toString(temp.left.val));
                str.append(',');
            }
            else{
                str.append("#,");
            }
            if(temp.right != null){
                Q.offerLast(temp.right);
                str.append(Integer.toString(temp.right.val));
                str.append(',');
            }
            else{
                str.append("#,");
            }
        }
        str.deleteCharAt(str.length()-1);
        return str.toString();
    }

    static Node deSerialize(String str){
        if(str.length() == 0){return null;}
        
        String[] values = str.split(",");
        Node root = new Node(Integer.valueOf(values[0]));
        ArrayDeque<Node> Q = new ArrayDeque<>();
        Q.offerLast(root); int i = 1;

        while(i<values.length){
            Node temp = Q.pollFirst();

            if(!values[i].equals("#")){
                Node lNode = new Node(Integer.valueOf(values[i]));
                temp.left = lNode;
                Q.offerLast(lNode);
            }
            i++;
            if(!values[i].equals("#")){
                Node rNode = new Node(Integer.valueOf(values[i]));
                temp.right = rNode;
                Q.offerLast(rNode);
            }
            i++;
        }

        return root;
    }

    static void preOrder(Node P){
        if(P != null){
            System.out.printf("%d ", P.val);
            preOrder(P.left);
            preOrder(P.right);
        }
    }
    public static void main(String[] args){
        Tree T = new Tree();
        T.createTree();
        String ser = serialize(T.root);
        System.out.println("\n-->> Serialized String: " + ser);

        Node root = deSerialize(ser);

        System.out.print("\n-->> PreOrder with the new Root: "); preOrder(root);

        System.out.println("\n");
    }
}
