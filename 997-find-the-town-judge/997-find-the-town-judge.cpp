class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int* count = new int[n+1]();
        for(vector<int> v:trust){
            count[v[0]]--;
            count[v[1]]++;
        }
        for(int i = 1;i<n+1;i++){
            if(count[i] == n-1)return i;
        }
        return -1;
    }
};