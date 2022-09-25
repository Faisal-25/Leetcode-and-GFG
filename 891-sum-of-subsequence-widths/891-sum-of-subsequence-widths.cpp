class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int p = 1;
        int sum = 0, mod = pow(10,9)+7;
        sort(begin(nums), end(nums));
        for(int i = 0;i<nums.size() && j>=0;i++, j--){
            sum = (sum+(long long int)p*nums[i] - (long long int)p*nums[j])%mod;
            p = (long long int)(p*2)%mod;
        }
        return sum;
    }
};