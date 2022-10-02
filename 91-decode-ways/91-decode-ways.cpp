class Solution {
public:
       int numDecodings(string s) {
        int*dp = new int[s.size() + 1];
        dp[0]= 1;
        dp[1] = s[0]-'0'>0?1:0;
        for(int i = 2;i<=s.size();i++){
            //the substring must be greater than 10
            
            dp[i] = s[i-1]-'0'!=0?dp[i-1]:0;
            int num = (stoi(s.substr(i-2,2))>=10 && stoi(s.substr(i-2,2))<=26)?dp[i-2]:0;
            dp[i]+=num;
        }
        
        return dp[s.size()];
    }
};