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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MAX);
    }
    TreeNode*helper(vector<int>&preorder, int bound){
        if(i==preorder.size()||preorder[i]>bound  ){
            return nullptr;
        }
        TreeNode*root = new TreeNode(preorder[i]);
        i++;
        root->left = helper(preorder,root->val);
        cout<<root->val<< " ";
        root->right = helper(preorder, bound);
        
        return root;
    }
};