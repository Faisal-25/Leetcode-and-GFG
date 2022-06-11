/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int lup(TreeNode*root,int val){
        if(root == nullptr)return 0;
        int lupLeft = lup(root->left,root->val);
        
        int lupRight = lup(root->right,root->val);
        count = max(count,lupLeft+lupRight+1);
        if(root->val!=val){
            return 0;
        }
        return max(lupLeft,lupRight)+1;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr)return 0;
        lup(root,0);
        return count-1;
    }
};