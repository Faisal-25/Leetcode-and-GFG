class Solution {
public:
    class triplet{
        public:
        int i;
        int j;
        int time;
        triplet(int i,int j,int time):i(i),j(j),time(time){}
    };
   struct compareTime {
    bool operator()(triplet const& t1, triplet const& t2)
    {
        return t1.time > t2.time;
    }
};
    int swimInWater(vector<vector<int>>& grid) {
        //make a priority queue where min element is at top
        priority_queue<triplet,vector<triplet>,compareTime> pq;
        //add the 0th element to pq;
        triplet t(0,0,grid[0][0]);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        pq.push(t);
        int maxElevation = INT_MIN;
        while(pq.empty() == false){
            triplet t1 = pq.top();
            pq.pop();
            if(visited[t1.i][t1.j] == 1)continue;
            visited[t1.i][t1.j] = 1;
            maxElevation = max(t1.time,maxElevation);
            if(t1.i == visited.size() - 1 && t1.j == visited[0].size() - 1){
                return maxElevation;
            }
            addN(pq,t1.i+1,t1.j,visited,grid);
            addN(pq,t1.i-1,t1.j,visited,grid);
            addN(pq,t1.i,t1.j+1,visited,grid);
            addN(pq,t1.i,t1.j-1,visited,grid);
            
        }
        return maxElevation;
    }
    void addN(priority_queue<triplet,vector<triplet>,compareTime> &pq,int i,int j,vector<vector<int>> &visited,vector<vector<int>>&grid){
        if(i>=0 && j>=0 && i<visited.size() && j<visited[0].size() && visited[i][j] == 0){
            triplet t(i,j,grid[i][j]);
            pq.push(t);
        }
        return;
    }
};