class Solution {
public:
    struct hashFunction 
{
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};
   unordered_set<vector<int>, 
  hashFunction> s;
    void permutations(vector<int>&nums,vector<bool> &check,vector<int> &v,int ci){
        //bool array of size nums.size() and apply recursive call
        if(ci == nums.size()){
            s.insert(v);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> check(nums.size());
        vector<int> v;
        permutations(nums,check,v,0);
        vector<vector<int>> ans;
        for(vector<int> v:s){
            ans.push_back(v);
        }
        return ans;
    }
};