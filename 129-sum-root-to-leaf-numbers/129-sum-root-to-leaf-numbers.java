/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int sum = 0;
    public int sumNumbers(TreeNode root) {
        sum =0;
        solve(root,"");
        return sum;
    }
    public void solve(TreeNode root,String num){
        if(root == null){
           
            return;
            
        }
        if(root.left == null && root.right == null){
            num+=root.val+"";
            sum+=Integer.parseInt(num);
            return;
        }
        solve(root.left,num+""+root.val);
        solve(root.right,num+""+root.val);
    }
}