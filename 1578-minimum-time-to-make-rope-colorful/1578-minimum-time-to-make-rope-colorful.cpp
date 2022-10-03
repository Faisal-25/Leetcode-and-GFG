class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        //ababaaaccedghh
        int sum_cost = 0;
        int max_cost = 0;
      
        int res = 0;
        for(int i = 0;i<s.size();i++){
            if(i>0 && s[i] != s[i-1]){
                res+=sum_cost-max_cost;
                sum_cost = 0;
                max_cost = 0;
                
            }
                
            sum_cost+=neededTime[i];
                max_cost = max(neededTime[i], max_cost);
            
        }
        res+=sum_cost-max_cost;
        return res;
    }
};