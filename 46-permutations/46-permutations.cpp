class Solution {
public:
    vector<vector<int>> ans;
    void permutations(vector<int>&nums,vector<bool> &check,vector<int> &v,int ci){
        //bool array of size nums.size() and apply recursive call
        if(ci == nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!check[i]){
                check[i]=true;
                v.push_back(nums[i]);
                permutations(nums,check,v,ci+1);
                v.pop_back();
                check[i] = false;
            }
            
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> check(nums.size());
        vector<int> v;
        permutations(nums,check,v,0);
        return ans;
    }
};