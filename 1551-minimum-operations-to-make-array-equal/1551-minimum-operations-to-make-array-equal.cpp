class Solution {
public:
    int minOperations(int n) {
        int sum = 0;
        vector<int> v;
        for(int i = 0;i<n;i++){
            v.push_back(2*i+1);
            sum+=(2*i+1);
        }
        int avg = sum/n;
        int i = 0, j = n-1,count = 0;
        while(i<j){
            count+=abs(avg-v[i]);
            i++;
            j--;
        }
        return count;
        
    }
};