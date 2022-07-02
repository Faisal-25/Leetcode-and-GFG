class Solution {
public:
    int find(int c){
        if(parent[c] == c)return c;
        else return parent[c] = find(parent[c]);
    }
    void union_(int p1,int p2){
        if(rank[p2]>rank[p1])parent[p2] = p1;
        else if(rank[p1]>=rank[p2]){
            if(rank[p1] == rank[p2]){
                rank[p1]++;
            }
            parent[p2] = p1;
        }
        
    }
    int*parent = new int[26];
    int*rank = new int[26];
    bool equationsPossible(vector<string>& e) {
        for(int i = 0;i<26;i++){
            parent[i] = i;
        }
        for(string eqn:e){
            if(eqn[1] == '='){
                int p1 = find(eqn[0]-'a');
                int p2 = find(eqn[3] -'a');
                if(p1!=p2){
                    union_(p1,p2);
                }
            }
        }
         for(string eqn:e){
            if(eqn[1] == '!'){
                int p1 = find(eqn[0]-'a');
                int p2 = find(eqn[3] -'a');
                if(p1==p2){
                 return false;   
                }
            }
        }
        return true;
    }
};