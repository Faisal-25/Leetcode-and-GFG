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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        if(!root->left && !root->right){
            return {to_string(root->val)};
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        vector<string> ans;
        for(int i = 0;i<left.size();i++){
            ans.push_back(to_string(root->val)+"->" + left[i]);
        }
        for(int i = 0;i<right.size();i++){
            ans.push_back(to_string(root->val) +"->"+ right[i]);
        }
        return ans;
    }
};