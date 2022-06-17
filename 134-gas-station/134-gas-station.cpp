class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumFuel = 0,sumGas = 0;
        for(int i = 0;i<gas.size();i++){
            sumFuel+=gas[i];
            sumGas += cost[i];
        }
        if(sumFuel<sumGas)return -1;
        int ans = -1;
        int sum = 0;
        for(int i = 0;i<gas.size();i++){
            sum=(sum+ gas[i] -cost[i]);
            cout<<sum<<" ";
            if(sum>=0 && ans == -1){
                cout<<sum<<endl;
                ans = i;
            }
            else if(sum<0){
                ans = -1;
                sum = 0;
            }
            
        }
        return ans;
    }
};