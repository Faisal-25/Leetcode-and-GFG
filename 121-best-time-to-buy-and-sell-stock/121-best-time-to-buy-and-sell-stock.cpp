class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = INT_MIN;
        int minDay = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            if(prices[i]<minDay){
                minDay = prices[i];
            }
          profit = max(profit,prices[i]-minDay);
        }
     return profit;
    }
};