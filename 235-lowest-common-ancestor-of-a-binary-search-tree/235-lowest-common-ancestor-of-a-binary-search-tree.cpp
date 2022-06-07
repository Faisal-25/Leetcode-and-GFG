/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = min(p->val, q->val), high = max(p->val, q->val);
        while(true)
        {
            if(low > root->val) root = root->right;
            else if(high >= root->val) return root;
            else root = root->left;
        }
        return root;
    }
};