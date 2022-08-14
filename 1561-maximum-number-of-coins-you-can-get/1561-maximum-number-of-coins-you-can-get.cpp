class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        sort(begin(piles), end(piles));
        for(int i = n/3;i<n;i+=2){
            sum+=piles[i];
        }
        return sum;
    }
};