class Solution {
public:
    bool isValid(int a,int b,int c){
        if((a+b)>c && (b+c)>a && (a+c)>b)return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        int j = nums.size() - 1;
        int i = nums.size() - 3;
        sort(nums.begin(),nums.end());
        while(i>=0){
            if(isValid(nums[i],nums[i+1],nums[i+2])){
                return nums[i]+ nums[i+1]+nums[i+2];
            }
            i--;
            j--;
        }
        return 0;
    }
};