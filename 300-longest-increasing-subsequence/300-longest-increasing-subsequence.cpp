class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),0);
        lis[0] = 1;
        for(int i = 1;i<lis.size();i++){
            int num = nums[i];
            int mx = 0;
            for(int j =i-1;j>=0;j--){
                if(num>nums[j]){
                    mx = max(lis[j],mx);
                }
            }
            lis[i] = mx + 1;
        }
        int ans = INT_MIN;
        for(int i = 0;i<lis.size();i++){
            ans= max(ans,lis[i]);
        }
        return ans;
    }
};