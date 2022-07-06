class Solution {
public:
    int*parent;
    int*rank;
    int find(int c){
        if(parent[c] == c)return c;
        return parent[c] = find(parent[c]);
    }
    void union_(int p1,int p2){
        if(rank[p1]>rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1] = p2;
        }
        else{
            parent[p2] = p1;
            rank[p1]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent = new int[isConnected.size()];
        rank = new int[isConnected.size()]();
        int n = isConnected.size();
        for(int i = 0;i<n;i++)parent[i] = i;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    int p1 = find(i);
                    int p2 = find(j);
                    if(p1!=p2){
                        union_(p1,p2);
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i)count++;
        }
        return count;
    }
};