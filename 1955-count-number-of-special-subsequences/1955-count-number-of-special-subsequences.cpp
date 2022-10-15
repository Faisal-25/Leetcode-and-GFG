class Solution {
public:
   int dp[100001][4] = {}, mod = 1000000007;
int dfs(vector<int>& nums, int i, int last) {
    if (i >= nums.size())
        return last == 2;
    if (dp[i][last + 1] == 0) {
        dp[i][last + 1] = 1 + dfs(nums, i + 1, last);
        if (nums[i] == last || nums[i] == last + 1)
            dp[i][last + 1] = (dp[i][last + 1] + dfs(nums, i + 1, nums[i])) % mod;
    }
    return dp[i][last + 1] - 1;
}
int countSpecialSubsequences(vector<int>& nums) {
    return dfs(nums, 0, -1);
}

};