class Pair{
    public:
    int ele;
    int bidx;
    int idx;
    Pair(int ele, int bidx, int idx){
        this->ele = ele;
        this->bidx = bidx;
        this->idx = idx;
    }
};
struct compareElement{
bool operator()(const Pair &p1, const  Pair &p2){
    return p1.ele>p2.ele;
}
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mx = INT_MIN;
         priority_queue<Pair, vector<Pair>, compareElement> pq;
        for(int i = 0;i<nums.size();i++){
            Pair p(nums[i][0],i,0);
            pq.push(p);
              mx = max(mx, nums[i][0]);
        }
        int mn = INT_MAX;
        int range = INT_MAX;
        int first = -1;
        int second = -1;
        while(pq.size()>=nums.size()){
          int  num = pq.top().ele;
          int bid = pq.top().bidx;
          int idx = pq.top().idx;
            pq.pop();
         
          
          if(mx - num < range){
           first = num;
            second = mx;
              range = mx-num;
          }
             else if(mx - num == range && num<first){
            first = num;
            second = mx;
        }
        if(idx + 1<nums[bid].size()){
            Pair p(nums[bid][idx+1],bid,idx+1);
            mx = max(mx, nums[bid][idx+1]);
            pq.push(p);
        }
      }
      return {first, second}; 
    }
};