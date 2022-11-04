class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int partitions = 1;
        int prev = 0;
        for(int cur = 1;cur<nums.size();cur++){
       
            if(nums[cur]-nums[prev] > k){
                
                partitions++;
                prev = cur;
            }
        }
        return partitions;
    }
};