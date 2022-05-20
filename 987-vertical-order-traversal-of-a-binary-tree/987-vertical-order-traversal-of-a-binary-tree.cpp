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
    class triplet{
        public:
        TreeNode* node;
        int h;
        int v;
        triplet(TreeNode* node, int h,int v){
            this->node = node;
            this->h = h;
            this->v = v;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<triplet>> m;
         queue<triplet> q;
        triplet t(root,0,0);
        q.push(t);
        int exLeft = INT_MAX;
        int exRight = INT_MIN;
        while(!q.empty()){
           triplet frontNode = q.front();
            m[frontNode.h].push_back(frontNode);
            exLeft = min(exLeft,frontNode.h);
            exRight = max(exRight,frontNode.h);
           
            if(frontNode.node->right){
                triplet temp(frontNode.node->right,frontNode.h+1,frontNode.v+1);
                q.push(temp);
            }
             if(frontNode.node->left){
                triplet temp(frontNode.node->left,frontNode.h-1,frontNode.v+1);
                q.push(temp);
            }
            q.pop();
           
        }
        for(auto &[key,v]:m){
            sort(v.begin(),v.end(),[](const triplet &t1,const triplet &t2){
                if(t1.v == t2.v){
                    return t1.node->val<t2.node->val;
                }
                return t1.v<t2.v;
            });
        }
        vector<vector<int>> ans;
        for(int i = exLeft;i<=exRight;i++){
            vector<triplet> v = m[i];
            vector<int> temp;
            for(triplet t:v){
                temp.push_back(t.node->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};