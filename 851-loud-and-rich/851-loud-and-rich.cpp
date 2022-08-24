class Solution {
public:
//     unordered_map<int,vector<int>> m;
    
//     vector<int> res;
//     int minQuite = INT_MIN;
//     int ans = -1;
//     void dfs(int i, vector<int>&quiet){
        
//         if(quiet[i]<minQuite){
//             minQuite = quiet[i];
//             ans = i;
//         }
        
        
//         for(int j:m[i]){
//            dfs(j,quiet);
//         }
//     }
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         for(vector<int> v:richer){
//             m[v[1]].push_back(v[0]);
//         }
       
//         res =vector<int>(quiet.size(),-1);
//         for(int i = 0;i<res.size();i++){
//             minQuite = INT_MAX;
//             ans = -1;
//             dfs(i,quiet);
          
//             res[i] =ans;
//         }
//         return res;
    // }
     unordered_map<int, vector<int>> richer2;
    vector<int> res;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for (auto v : richer) richer2[v[1]].push_back(v[0]);
        res = vector<int> (quiet.size(), -1);
        for (int i = 0; i < quiet.size(); i++) dfs(i, quiet);
        return res;
    }

    int dfs(int i, vector<int>& quiet) {
        if (res[i] >= 0) return res[i];
        res[i] = i;
        for (int j : richer2[i]) {
            int ans = dfs(j,quiet);
            if (quiet[res[i]] > quiet[ans]) {
                res[i] = res[j];
            }
        }
        return res[i];
    }
};