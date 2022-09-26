class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> nge(nums.size());
        stack<int> s;
        int n = nums.size();
        nge[n-1] = n;
        s.push(nums.size() -1 );
        for(int i = nums.size() - 2;i>=0;i--){
            while(s.size()>0 && nums[s.top()]<=nums[i]){
                s.pop();
            }
        
            if(s.size() == 0){
                nge[i] = n;
            }else{
                nge[i] = s.top();
            }
            s.push(i);
        }
        vector<int> ans(n-k+1);
        int j = 0;
        for(int i = 0;i<ans.size();i++){
            if(j<i){
                j  = i;
            }
            while((nge[j]-i)<k){
                j = nge[j];
            }
            ans[i] = nums[j];
        }
        return ans;
        
    }
};