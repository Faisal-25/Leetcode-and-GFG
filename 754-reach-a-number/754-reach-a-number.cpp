class Solution {
public:
    int reachNumber(int target) {
        target =abs(target);
       int count = 0;
        int sum = 0;
        int i = 1;
        while(true){
            count++;
            sum+=i;
            if(sum>=target && (sum-target)%2 == 0){
                return count;
            }
            i++;
        }
        return -1;
    }
};