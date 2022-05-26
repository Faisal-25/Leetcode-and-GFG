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
    int maxSum = INT_MIN;
    int maxSumPath(TreeNode* root) {
        if(root == nullptr)return 0;
        
        int left = maxSumPath(root->left);
        int right = maxSumPath(root->right);
        int _left = max(left,0);
        int _right = max(right,0);
        maxSum = max(maxSum,root->val+_left+_right);
        return root->val + max(_left,_right);
    }
    int maxPathSum(TreeNode*root){
        int ans =  maxSumPath(root);
    
        return maxSum;
    }
};