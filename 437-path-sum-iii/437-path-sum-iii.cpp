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
    int count = 0;
    private:
    void PS_2(TreeNode*root, int targetSum, long long int sum ,vector<int> s){
        if(root == NULL)return;
        sum+=root->val;
        s.push_back(root->val);
        if(sum == targetSum){
            count++;
            int dum = sum;
            for(int i = 0;i<s.size()-1;i++){
                dum = dum-s[i];
                if(dum == targetSum){
                    count++;
                }
            }
        }
        else {
            long long int  dum = sum;
            for(int i = 0;i<s.size()-1;i++){
                dum = dum - s[i];
                if(dum == targetSum){
                    count++;
                }
            }
        }
     
        PS_2(root->left, targetSum,sum,s);
        PS_2(root->right, targetSum,sum,s);
    }
    public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return 0;
        vector<int> s;
        long long int sum = 0;
        PS_2(root, targetSum,sum,s);
        return count;
    }
};