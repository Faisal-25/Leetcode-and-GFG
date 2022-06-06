/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    static class Pair{
        int state;
        TreeNode node;
        Pair(TreeNode node,int state){
            this.state = state;
            this.node = node;
        }
    }
   
   public static void preorder(TreeNode root,StringBuilder str){
        if(root == null){
             str.append(".");
            str.append(" ");
           
            return;
        }
        str.append(root.val+"");
       str.append(" ");
        preorder(root.left,str);
        preorder(root.right,str);
        
    }
    public String serialize(TreeNode root) {
        if(root == null)return "";
        StringBuilder str = new StringBuilder();
        preorder(root, str);
        String ans = str.toString();
        
        return ans;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.length() == 0)return null;
        Stack<Pair> s = new Stack<>();
        String [] c = data.split(" ");
        for(int i = 0;i<c.length;i++){
            System.out.print(c[i]);
        }
        int idx = 0;
        Pair rp = new Pair(new TreeNode(Integer.parseInt(c[0])),0);
        s.push(rp);
        TreeNode root = rp.node; 
        idx = 1;
        while(s.size()>0){
            Pair p = s.peek();
            if(p.state == 0){
                if(c[idx].equals(".")){
                     System.out.print(c[idx]);
                    p.state++;
                }
                else{
                    p.state++;
                    
                    TreeNode pn = new TreeNode(Integer.parseInt(c[idx]));
                    
                    p.node.left = pn;
                    s.push(new Pair(pn,0));
                }
                idx++;
            }
            else if(p.state == 1){
                 if(c[idx].equals(".")){
                    p.state++;
                }
                else{
                    p.state++;
                    TreeNode pn = new TreeNode(Integer.parseInt(c[idx]));
                    p.node.right = pn;
                    s.push(new Pair(pn,0));
                }
                idx++;
            }
            else{
                s.pop();
            }
            
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));