class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        int n = nums.size();
        for(int j = 0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i] = nums[j];
                i++;
            }
            else{
                k++;
            }
        }
        for(int i = n-k;i<n;i++){
            nums[i] = 0;
        }
        return n-k;
    }
};