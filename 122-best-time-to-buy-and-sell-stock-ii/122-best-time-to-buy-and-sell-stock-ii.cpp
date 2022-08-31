class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int sd = 0;
       int bd = 0;
        int n = prices.size();
        int prof = 0;
       for(int i = 1;i<n;i++){
           if(prices[i]>prices[i-1]){
               sd = i;
           }
           else{
               prof += prices[sd]-prices[bd];
               sd = bd = i;
           }
       }
        prof+=prices[sd] - prices[bd];
        return prof;
        
    }
};