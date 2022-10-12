class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0;
        priority_queue<long> pq;
        for(int ele:target){
            pq.push(ele);
            sum+=ele;
        }
        while(true){
            int mx = pq.top();
            pq.pop();
            sum-=mx;
            if(mx == 1 || sum == 1 ){
                return true;
            }
            if(sum<=0 || mx<sum ||mx%sum == 0){
                return false;
            }
            mx%=sum;
            sum+=mx;
            pq.push(mx);
        }
        return true;
    }
};