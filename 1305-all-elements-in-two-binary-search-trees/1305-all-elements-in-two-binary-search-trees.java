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
    
    public void inorder(TreeNode root, List<Integer> bst){
        if(root == null)return;
        inorder(root.left, bst);
        bst.add(root.val);
        inorder(root.right,bst);
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> bst1 = new LinkedList<>();
    List<Integer> bst2 = new LinkedList<>();
        inorder(root1,bst1);
        inorder(root2,bst2);
        List<Integer> ans = new LinkedList<>();
        int i = 0;
        int j = 0;
        while(i<bst1.size() && j<bst2.size()){
            if(bst1.get(i)<bst2.get(j)){
                ans.add(bst1.get(i));
                i++;
            }
            else{
                ans.add(bst2.get(j));
                j++;
            }
        }
        while(i<bst1.size()){
            ans.add(bst1.get(i));
            i++;
        }
        while(j<bst2.size()){
            ans.add(bst2.get(j));
            j++;
        }
        return ans;
    }
}