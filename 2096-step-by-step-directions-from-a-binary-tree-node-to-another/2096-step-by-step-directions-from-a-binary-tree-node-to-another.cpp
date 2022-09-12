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
    vector<TreeNode*> nodeToRootPath(TreeNode*root, int node){
        if(root == nullptr){
            return {};
        }
        if(root->val == node){
            return {root};
        }
        vector<TreeNode*> left = nodeToRootPath(root->left, node);
        if(left.size()>0){
            left.push_back(root);
            return left;
        }
        vector<TreeNode*> right = nodeToRootPath(root->right, node);
        if(right.size()>0){
            right.push_back(root);
            return right;
        }
        return {};
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<TreeNode*> v1 = nodeToRootPath(root, startValue);
        vector<TreeNode*> v2 = nodeToRootPath(root, destValue);
        int i=v1.size() - 1;
        int j = v2.size() - 1;
        while(i>=0 && j>=0){
            if(v1[i] == v2[j]){
                i--;j--;
            }else{
               
                break;
            }
        }
         i++;j++;
        cout<<i<<" "<<j<<endl;
        string ans = "";
        for(int ii = 0;ii<i;ii++){
            ans+="U";
        }
        for(int jj = j;jj>0;jj--){
            if(v2[jj-1] == v2[jj]->left){
                ans+="L";
            }else{
                ans+="R";
            }
        }
        return ans;
    }
};