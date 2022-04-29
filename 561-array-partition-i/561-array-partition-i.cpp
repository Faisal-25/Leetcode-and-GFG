class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum+= i%2==0?nums[i]:0;
        }
        return sum;
    }
};