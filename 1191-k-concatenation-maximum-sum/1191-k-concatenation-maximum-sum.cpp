class Solution {
    public:
     int mod = pow(10,9)+7;
     int kadane(vector<int> &arr){
        int curSum = 0;
        int maxSum = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            curSum+=arr[i];
            if(maxSum<curSum){
                maxSum = curSum;
            }
            if(curSum<0){
                curSum = 0;
            }
        }
        
     
        return maxSum%mod;
        
    }
     int kConcatenationMaxSum(vector<int> &arr, int k) {
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
        }
        // System.out.println(sum);
        vector<int> newArr(2*arr.size());
        for(int i = 0;i<2*arr.size();i++){
            if(i<arr.size()){
                newArr[i] = arr[i];
            }
            else{
                newArr[i] = arr[(i-arr.size())];
            }
            
        }
         if(k == 1){
            return kadane(arr);
        }
  
        int ans = kadane(newArr);
        if(sum<0){
            
            return ans>0?ans:0;
        }
        return (ans + (long long int)((long long int)(k-2)*sum))%mod;
       
        
    }
};