/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root == null)return null;
        root.next = null;
        Node curr = root;
        Node head = null;
        Node tail = null;
        while(curr!=null){
            while(curr!=null){
                if(curr.left!=null){
                    if(head == null){
                         head = curr.left;
                       tail = curr.left;
                    }else{
                         tail.next = curr.left;
                    tail = tail.next;
                    }
                   
                }
                if(curr.right!=null){
                    if(head == null){
                    head = curr.right;
                    tail = curr.right;
                    }
                    else{
                          tail.next = curr.right;
                    tail = tail.next;
                    }
                }
              
                curr = curr.next;
            }
           curr = head;
            head = null;
            tail = null;
        }
        return root;
    }
}