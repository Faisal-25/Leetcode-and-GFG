class Solution {
public:
    int lps(string str){
        vector<vector<int>> dp(str.size(),vector<int>(str.size()));
        int maxLen = INT_MIN;
        for(int g = 0;g<dp[0].size();g++){
           for(int i = 0, j = g;j<dp[0].size();i++,j++){
               if(g == 0){
                   dp[i][j] = 1;
               }
               else if(g == 1){
                   dp[i][j] = (str[i] == str[j])?2:1;
               }
               else{
                   if(str[i] == str[j]){
                       dp[i][j] = dp[i+1][j-1]+2;
                   }else{
                       dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                   }
                   
               }
               maxLen = max(maxLen,dp[i][j]);
           }
           
       }
        return maxLen;
    }
    int minInsertions(string s) {
        return s.size() - lps(s);
    }
};