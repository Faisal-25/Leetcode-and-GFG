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
    bool inorder(TreeNode*root, TreeNode*&prev){
        if(root == nullptr)return true;
        bool leftAns = inorder(root->left,prev);
        if(!leftAns)return leftAns;
        if(prev!=nullptr && prev->val>=root->val) return false;
        prev = root;
        bool rightAns = inorder(root->right,prev);
        return rightAns;
    
    }
    bool isValidBST(TreeNode*root){
        TreeNode*prev = nullptr;
       return inorder(root, prev);
       
    }
};
