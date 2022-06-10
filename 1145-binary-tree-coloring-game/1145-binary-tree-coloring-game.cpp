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
    int size(TreeNode*root, int n,int x,int &xLeft,int &xRight){
        if(root == nullptr)return 0;
        int leftSize = size(root->left, n, x, xLeft, xRight);
        int rightSize = size(root->right, n, x, xLeft, xRight);
        if(root->val == x){
            xLeft = leftSize;
            xRight = rightSize;
            cout<<leftSize<<" "<<rightSize<<endl;
        }
        return rightSize+leftSize+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int xLeft = -1;
        int xRight = -1;
        size(root,n,x,xLeft,xRight);
        cout<<xLeft<<" "<<xRight<<endl;
        return n-max(n-(xLeft+xRight+1),max(xLeft,xRight))<max(n-(xLeft+xRight+1),max(xLeft,xRight));
    }
};