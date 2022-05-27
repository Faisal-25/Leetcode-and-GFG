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
    TreeNode* createBST(vector<int>&preorder, int min, int max){
        
        if(i<preorder.size() && preorder[i]>min && preorder[i]<max){
            TreeNode*root = new TreeNode(preorder[i]);
            i++;
            root->left = createBST(preorder,min,root->val);
          
           
            
                root->right = createBST(preorder,root->val,max);
            
            return root;
        }
        else{
            return nullptr;
        }
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createBST(preorder,INT_MIN,INT_MAX);
    }
};