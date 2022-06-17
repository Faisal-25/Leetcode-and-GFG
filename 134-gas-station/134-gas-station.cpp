class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      
        int ans = -1;
        int sumFuel = 0;
        int sumGas = 0;
        int sum = 0;
        for(int i = 0;i<gas.size();i++){
            sumFuel+=gas[i];
            sumGas+=cost[i];
            sum+=(gas[i] -cost[i]);
         
            if(sum>=0 && ans == -1){
               
                ans = i;
            }
            else if(sum<0){
                ans = -1;
                sum = 0;
            }
            
        }
        
        return sumFuel<sumGas?-1:ans;
    }
};