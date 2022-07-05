class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int* count  = new int[edges.size()+2]();
        for(vector<int> v:edges){
            count[v[0]]++;
            count[v[1]]++;
        }
       for(int i = 0;i<edges.size()+2;i++){
           if(count[i] == edges.size())return i;
       }
        return -1;
    }
};