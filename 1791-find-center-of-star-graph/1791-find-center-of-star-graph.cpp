class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int* count  = new int[edges.size()+2]();
        for(vector<int> v:edges){
            count[v[0]]++;
            count[v[1]]++;
            if(count[v[0]] == edges.size())return v[0];
            if(count[v[1]] == edges.size())return v[1];
        }
     
        return -1;
    }
};