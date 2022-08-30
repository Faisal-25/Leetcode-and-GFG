class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minCost = INT_MAX;
        int n = prices.size();
        for(int i = 0;i<n;i++){
            minCost = min(minCost, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minCost);
        }
        return maxProfit;
    }
};