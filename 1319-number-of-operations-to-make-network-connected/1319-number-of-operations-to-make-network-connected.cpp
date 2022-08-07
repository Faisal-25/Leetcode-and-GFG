class Solution {
public:
    int find(int c,vector<int>&parent){
        if(parent[c] == c)return c;
        return parent[c] = find(parent[c],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<int> parent(n);
        for(int i = 0;i<n;i++)parent[i] = i;
        for(int i = 0;i<connections.size();i++){
            int x = find(connections[i][0],parent);
            int y = find(connections[i][1],parent);
            if(x!=y)parent[y] = x;
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(parent[i] ==i)ans++;
        }
        return ans;
    }
};