class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int*prefix = new int[nums.size()]();
        int *suffix = new int[nums.size()]();
        int k = nums.size() - 1;
        for(int i = 0;i<nums.size();i++,k--){
            if(i == 0)prefix[i] = nums[i];
            else prefix[i]+=prefix[i-1]+nums[i];
            if(k == nums.size() - 1)suffix[k] = nums[k];
            else suffix[k] = suffix[k+1]+nums[k];
        }
        for(int i = 0;i<nums.size();i++){
            if(prefix[i] == suffix[i])return i;
        }
        return -1;
    }
    
};