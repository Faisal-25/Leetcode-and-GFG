class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> res(nums.size());
        sort(nums.begin(),nums.end());
        int i = 1;
        int j = nums.size()-1;
        while(i<nums.size()){
            res[i] = nums[j];
            i+=2;
            j--;
        }
        i = 0;
        while(i<nums.size()){
            res[i] = nums[j];
            i+=2;
            j--;
        }
        nums = res;
     
    }
};