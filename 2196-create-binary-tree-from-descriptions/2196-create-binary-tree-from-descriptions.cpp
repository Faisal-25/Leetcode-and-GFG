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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodes;
        set<int> children;
        for(vector<int> v:descriptions){
            int parent = v[0] , child = v[1], isLeft = v[2];
            if(nodes.count(v[0]) == 0){
                nodes[v[0]] = new TreeNode(v[0]);
            }
            if(nodes.count(v[1]) == 0){
                nodes[v[1]] = new TreeNode(v[1]);
            }
            if(isLeft == 1){
                nodes[v[0]]->left = nodes[v[1]];
            }else{
                nodes[v[0]]->right = nodes[v[1]];
            }
            children.insert(v[1]);
        }
       int root = -1;
        for(int i = 0;i<descriptions.size();i++){
            if(children.find(descriptions[i][0]) == children.end()){
                root =descriptions[i][0];
            }
        }
        return nodes[root];
    }
};