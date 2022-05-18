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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)return {};
         queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    q.push(nullptr);
    s.push(root);
    s.push(nullptr);
    while(!q.empty()){
        TreeNode*frontNode = q.front();
        
        if(frontNode == nullptr){
            
          
             q.pop();
            if(q.size()){
                 s.push(nullptr);
                q.push(nullptr);
            }
        }
        else{
        if(frontNode->right){
            q.push(frontNode->right);
            s.push(frontNode->right);
        }
        if(frontNode->left){
            q.push(frontNode->left);
            s.push(frontNode->left);
        }
            q.pop();
        }
    
    }
     vector<vector<int>> ans;
    vector<int> temp;
        s.pop();
        while(s.size()){
        
              if(s.top() == nullptr){
                  ans.push_back(temp);
                  temp.clear();
              }
              else {
                  temp.push_back(s.top()->val);
                  
              }
                s.pop();
            
            
           
        }
        ans.push_back(temp);
        return ans;
    }
};