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
    TreeNode* buildMaxBT(vector<int>&nums,int si,int ei){
        if(si>ei)return nullptr;
        int maxVal = INT_MIN;
        int idx = -1;
        for(int i = si;i<=ei;i++){
            if(maxVal<nums[i]){
                maxVal = nums[i];
                idx = i;
            }
           
        }
        TreeNode*root = new TreeNode(maxVal);
        root->left = buildMaxBT(nums,si,idx-1);
        root->right = buildMaxBT(nums,idx+1,ei);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildMaxBT(nums,0,nums.size()-1);
    }
};