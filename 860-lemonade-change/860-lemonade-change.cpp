class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int n5 = 0;
        int n10 = 0;
        int n20 = 0;
        for(int i = 0;i<bills.size();i++){
            if(bills[i] == 5)n5++;
            else if(bills[i] == 10){
                if(n5 ==0)return false;
                else{ 
                    n5--; 
                    n10++;
                }
            }
            else{
                if(n5>=1 && n10>=1){
                   n5--;
                    n10--;
                    
                }
                else if(n5>=3){
                    n5-=3;
                    
                }
                else{
                    cout<<2<<" "<<i<<" "<<n10<<" "<<n5;
                    return false;
                }
            }
        }
        return true;
    }
};