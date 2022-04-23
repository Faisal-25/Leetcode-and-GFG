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
    int sum = 0;
    public void leftLeavesSum(TreeNode root,boolean flag){
        if(root == null)return;
        if(root.left==null && root.right == null && flag == true){
            sum+=root.val;
        }
        leftLeavesSum(root.left,true);
        leftLeavesSum(root.right,false);
    }
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null)return 0;
        leftLeavesSum(root,false);
        return sum;
    }
}