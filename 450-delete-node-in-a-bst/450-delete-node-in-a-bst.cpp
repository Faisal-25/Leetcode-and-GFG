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
    int leftMax(TreeNode*root){
        return root?max(root->val,max(leftMax(root->left),leftMax(root->right))):INT_MIN;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return NULL;
        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left && root->right){
                int lmax = leftMax(root->left);
                root->val = lmax;
                root->left = deleteNode(root->left,lmax);
                
                
            }
            else if(root->left){
                return root->left;
            }
            else if(root->right){
                return root->right;
            }
            else{
                return nullptr;
            }
        }
        return root;
    }
};