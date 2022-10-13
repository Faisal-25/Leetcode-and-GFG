class Solution {
public:
    int max_coins(vector<int>&nums, int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        int maxCoins = INT_MIN;
        for(int ind = i;ind<=j;ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1] + max_coins(nums,i,ind-1,dp) + max_coins(nums,ind+1,j,dp);
            maxCoins = max(maxCoins, cost);
        }
        return dp[i][j] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
            nums.insert(nums.begin(), 1);
            nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
          return max_coins(nums,1,nums.size()-2,dp);
    }
};