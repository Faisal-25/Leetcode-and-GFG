class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1,vector<bool>(s.size()+1,false));
        int n = dp.size();
        int m = dp[0].size();
        dp[n-1][m-1] = true;
 for(int i=p.size()-1;i>=0;i--){
            if(p[i]!='*')
                break;
            else
                dp[i][s.size()]=true;
        }
        for(int i = n-2;i>=0;i--){
            for(int j = m-2;j>=0;j--){
                if(p[i] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }else if(p[i] == '*'){
                    for(int k = j;k<m;k++){
                        if(dp[i+1][k]){
                            dp[i][j] = true;
                            break;
                        }
                    }
                }else{
                    if(p[i] == s[j]){
                        dp[i][j] = dp[i+1][j+1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[0][0];
    }
};
