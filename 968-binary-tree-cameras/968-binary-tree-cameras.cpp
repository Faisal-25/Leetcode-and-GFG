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
    int cameras = 0;
    int minCameraCover1(TreeNode*root){
        if(root == nullptr)return 1;
        
        int leftChild = minCameraCover1(root->left);
        int rightChild = minCameraCover1(root->right);
        if(leftChild == -1 || rightChild == -1){
            cameras++;
            return 0;
        }
        if(leftChild == 0 || rightChild == 0){
            return 1;
        }
        if(leftChild == 1 || rightChild == 1){
            return -1;
        }
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        if(minCameraCover1(root) == -1){
            return cameras+1;
        }
        return cameras;
    }
};