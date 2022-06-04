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
    static class pair{
        int nodes;
        int coins;
        pair(){
            
        }
        pair(int nodes,int coins){
            this.nodes = nodes;
            this.coins = coins;
        }
    }
    int coins = 0;
    public int distributeCoins(TreeNode root) {
        minMoves(root);
        return coins;
    }
    public pair minMoves(TreeNode root){
        if(root == null){
            return new pair(0,0);
        }
        pair lp = minMoves(root.left);
        pair rp = minMoves(root.right);
        pair np = new pair();
        np.nodes = lp.nodes+rp.nodes+1;
        np.coins = lp.coins + rp.coins + root.val;
        if(Math.abs(np.nodes - np.coins)>0){
            coins +=Math.abs(np.nodes - np.coins);
        }
        return np;
        
    }
}