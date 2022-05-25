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
    
    
    
     TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
//     TreeNode*buildTree1(vector<int>&inorder,vector<int>&postorder,int pl,int ph,int il,int ih){
        
//         if(pl>ph||il>ih)return nullptr;
        
        
        
//         TreeNode*root = new TreeNode(postorder[ph]);
     
//         int i = il;
//         while(inorder[i]!=root->val);{
//             i++;
//              cout<<1<<" ";
//         }
       
//         root->left = buildTree1(inorder,postorder,pl,pl+i-il-1,il,i-1);
//         root->right = buildTree1(inorder,postorder,pl+i-il,ph-1,i+1,ih);
//         return root;
// //          node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
// //         node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        
        
        
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         TreeNode*root = buildTree1(inorder, postorder,0,postorder.size()-1,0,inorder.size()-1);
//         return root;
//     }
    
};