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
    
    unordered_map<int,int> m;
    int count = 0;
    void pathSumIII(TreeNode*root,long long int sum,int targetSum){
        if(root == nullptr)return;
        sum+=root->val;
          if(m[sum-targetSum]>0){
            count+=m[sum-targetSum];
        }
        m[sum]++;
      
        pathSumIII(root->left, sum,targetSum);
        pathSumIII(root->right,sum,targetSum);
    
        m[sum]--;
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)return 0;
        if(root->left == NULL and root->right == NULL){
            if(root->val!=targetSum)return 0;
        }
        unordered_map<int,int> t;
        m = t;
        m[0]++;
        pathSumIII(root,0,targetSum);
        return count;
    }
};