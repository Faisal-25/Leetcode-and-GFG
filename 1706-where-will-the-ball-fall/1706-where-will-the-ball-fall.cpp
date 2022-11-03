class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int i1 = 0, i2;
        vector<int> res;
        for(int i = 0;i<n;i++){
            i1 = i;
            for(int j = 0;j<m;j++){
                i2 = i1 + grid[j][i1];
                if(i2<0 || i2>=n || grid[j][i1]!=grid[j][i2]){
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            res.push_back(i1);
        }
        return res;
    }
};