class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == key){
                if(i<n-1){
                    m[nums[i+1]]++;
                }
            }
        }
        int maxV = INT_MIN;
        int maxK = -1;
        for(auto &[k,v]:m){
            if(v>maxV){
                maxK = k;
                maxV = v;
            }
        }
        return maxK;
    }
};