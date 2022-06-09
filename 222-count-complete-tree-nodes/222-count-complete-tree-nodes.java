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
    int count = 0;
    
    int  travel(TreeNode root,int k){
        if(root.left == null && root.right == null){
            return k;
        }
       return travel(root.left,k+1);
    }
    void solve(TreeNode root, int k,int h){
        if(k == h){
            if(root == null)count--;
            return;
        }
        solve(root.right,k+1,h);
        solve(root.left,k+1,h);
    }
    public int countNodes(TreeNode root) {
        if(root == null)return 0;
        int h= travel(root,0);
        int a = 1;
         count = a*((int)Math.pow(2,h+1)-1);
         solve(root,0,h);
        return count;
    }
}