/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                temp.push_back(q.front()->val);
                vector<Node*> children = q.front()->children;
                for(Node*n:children){
                    q.push(n);
                }
                q.pop();
                
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};