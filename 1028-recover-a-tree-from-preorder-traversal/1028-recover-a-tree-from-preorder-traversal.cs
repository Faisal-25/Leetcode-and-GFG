/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode RecoverFromPreorder(string S) {
        Dictionary<int, TreeNode> _lastAtLevel = new Dictionary<int, TreeNode>();
        
        int currentLevel=0;
        int lastIndex=0;
        
        while(lastIndex<S.Length){
            currentLevel=0;
            
            while(lastIndex<S.Length && S[lastIndex]=='-'){
                lastIndex++;
                currentLevel++;
            }

            int valStartIndex = lastIndex;

            while(lastIndex<S.Length && S[lastIndex]!='-'){
                lastIndex++;
            }

            string val=S.Substring(valStartIndex, lastIndex-valStartIndex);

            TreeNode tn = new TreeNode(int.Parse(val));

            if(currentLevel>0){
                TreeNode parent = _lastAtLevel[currentLevel-1];

                if(parent.left==null){
                    parent.left = tn;
                }
                else{
                    parent.right = tn;
                }
            }

            _lastAtLevel[currentLevel]=tn;
        }
        
        return _lastAtLevel[0];
    }   
}