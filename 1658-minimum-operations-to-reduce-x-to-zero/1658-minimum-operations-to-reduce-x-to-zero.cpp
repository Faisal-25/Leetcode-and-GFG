class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
     
        unordered_map<int,int> m;
        int prefixSum = 0,sum = 0,n = nums.size(),ans = INT_MIN;
        m[0] = -1;
        for(int i = 0;i<n;i++)sum+=nums[i];
        if(sum<x)return -1;
        if(sum == x)return nums.size();
        int targetSum = sum-x;
        for(int i = 0;i<n;i++){
            prefixSum+=nums[i];
            if(m.find(prefixSum-targetSum)!=m.end()){
                ans = max(i-m[prefixSum-targetSum],ans);
            }
           
            m[prefixSum] = i;
        }
        return ans == INT_MIN?-1:nums.size() - ans;
    }
};