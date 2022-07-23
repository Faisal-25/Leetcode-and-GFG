class Solution {
public:
    int minOperations(int n) {
        int avg = (n*n)/n;
        int count = 0;
        
        for(int i = 0;i<n/2;i++){
            count+=abs(avg-(2*i+1));
        }
      
        return count;
        
    }
};