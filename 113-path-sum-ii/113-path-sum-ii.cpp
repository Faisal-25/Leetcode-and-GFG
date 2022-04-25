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
    vector<vector<int>> ans;
    void pathSumII(TreeNode*root,int targetSum,int currSum,vector<int> v){
        if(root == nullptr)return;
        if(!root->left && !root->right){
            if(currSum+root->val == targetSum){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        pathSumII(root->left,targetSum,currSum+root->val,v);
      
        pathSumII(root->right,targetSum,currSum+root->val,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return {};
        }
        vector<int> v;
        pathSumII(root,targetSum,0,v);
        return ans;
    }
};