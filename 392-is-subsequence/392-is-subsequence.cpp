class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
        for(int i = 0;i<dp.size();i++){
            for(int j = 0;j<dp[0].size();j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
                    }
                    else{
                       dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};