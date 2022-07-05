class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int* count  = new int[edges.size()+2]();
        // for(vector<int> v:edges){
        //     count[v[0]]++;
        //     count[v[1]]++;
        //     if(count[v[0]] == edges.size())return v[0];
        //     if(count[v[1]] == edges.size())return v[1];
        // }
       
        if(edges[0][0] == edges[1][0])return edges[0][0];
        else if(edges[0][0] == edges[1][1])return edges[0][0];
      else if(edges[0][1] == edges[1][0])return edges[0][1];
        else if(edges[0][1] == edges[1][1])return edges[0][1];
        
     return 0;
    }
};