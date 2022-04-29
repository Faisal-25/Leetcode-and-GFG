class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minDiff = INT_MAX;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j<n){
            if(j-i+1 == k){
                minDiff = min(nums[j]-nums[i],minDiff);
                i++;
            }
            j++;
        }
        return minDiff==INT_MAX?0:minDiff;
    }
};