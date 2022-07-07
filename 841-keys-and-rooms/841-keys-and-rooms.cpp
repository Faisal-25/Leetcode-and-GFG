class Solution {
public:
    void dfs(int src, vector<vector<int>>&rooms,vector<bool>&visited){
        visited[src] = true;
        for(int v:rooms[src]){
            if(!visited[v]){
                dfs(v,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0;
        vector<bool> visited(rooms.size());
       for(int i = 0;i<rooms.size();i++){
           if(!visited[i]){
               dfs(i,rooms,visited);
               count++;
           }
       }
        return count == 1;
    }
};