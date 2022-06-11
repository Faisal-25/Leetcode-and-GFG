// { Driver Code Starts
//Initial Template for Java
import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node{
    public int data;
    public Node left,right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }
    static void printInorder(Node root) {
        if (root == null) return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution obj = new Solution();
            System.out.println(obj.imgMultiply(root));
            t--;
        }
    }
}// } Driver Code Ends


//User function Template for Java
/* Tree node structure  used in the program
class Node{
    public int data;
    public Node left,right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
 */
 class Solution {
     long sum = 0;
     long mod = (long)(Math.pow(10,9))+7;
     public void multiplyImage(Node root1,Node root2){
         if(root1 == null || root2 == null)return;
         sum+=(root1.data*root2.data)%mod;
         multiplyImage(root1.left,root2.right);
         multiplyImage(root1.right,root2.left);
         
     }
    public long imgMultiply(Node root)
    {
        sum = 0;
        sum+=(root.data*root.data)%mod;
        multiplyImage(root.left,root.right);
        return sum%mod;
    }
}