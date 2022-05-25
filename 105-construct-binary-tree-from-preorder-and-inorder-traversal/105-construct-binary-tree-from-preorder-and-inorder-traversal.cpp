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
    TreeNode* buildTree1(vector<int>&preorder, vector<int>&inorder,int pl,int ph,int il,int ih){
        
        
        if(pl>ph||il>ih)return nullptr;
        TreeNode*root =  new TreeNode(preorder[pl]);
        int val = preorder[pl];
        int i = il;
        while(inorder[i]!=val){
            i++;
        }
       root->left = buildTree1(preorder,inorder,pl+1,pl+i-il,il,i-1);
        root->right = buildTree1(preorder,inorder,pl+i-il+1,ph,i+1,ih);
        return root;
        
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode*root  = buildTree1(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};