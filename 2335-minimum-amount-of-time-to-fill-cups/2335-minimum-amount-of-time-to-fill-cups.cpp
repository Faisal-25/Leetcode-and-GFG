class Solution {
public:
    int fillCups(vector<int>& amount) {
      
        int sum = 0;
        int mx = INT_MIN;
        for(int a:amount){
            mx = max(a,mx);
            sum+=a;
        }
        return max(mx,((sum+1)/2));
    }
};