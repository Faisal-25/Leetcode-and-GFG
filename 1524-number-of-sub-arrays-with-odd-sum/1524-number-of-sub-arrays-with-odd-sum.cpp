class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long ans = 0;
        int oddSumCount = 0;
        int evenSumCount = 0;
        int sum = 0;
        for(int num:arr){
            sum+=num;
            if(sum%2){
                ans+=1+evenSumCount;
                oddSumCount++;
            }
            else{
                ans+=oddSumCount;
                evenSumCount++;
            }
        }
        int mod = pow(10,9)+7;
        return (int)(ans%mod);
    }
};