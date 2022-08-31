class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obsp = -prices[0];
        int ossp = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++){
            int nbsp = max(ossp-prices[i],obsp);
            int nssp = max(obsp+prices[i]-fee,ossp);
            cout<<nbsp<<" "<<nssp<<endl;
            ossp = nssp;
            obsp = nbsp;
        }
        return ossp;
    }
};