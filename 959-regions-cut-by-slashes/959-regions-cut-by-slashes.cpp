class Solution {
public:
    int* parent = new int[5];
    int*rank = new int[5];
    void _union(int p1,int p2){
        if(rank[p1]>rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1] = p2;
        }
        else{
            parent[p2] = p1;
            rank[p1]++;
        }
    }    
    void unionHelper(int x, int y){
        int xl = find(x);
        int yl = find(y);
        
        if(xl != yl){
            _union(xl, yl);
        }
    }
    int find(int c){
        if(parent[c] == c)return c;
        return parent[c] = find(parent[c]);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = 4*grid.size()*grid[0].size();
        parent = new int[4*grid.size()*grid[0].size()];
        rank = new int[4*grid.size()*grid[0].size()]();
        for(int i = 0;i<n;i++)parent[i] = i;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
                  char ch = grid[i][j];
                
                int bno = i * grid.size() + j;
                
                if(ch != '/'){
                    unionHelper(4 * bno + 0, 4 * bno + 1);
                    unionHelper(4 * bno + 2, 4 * bno + 3);
                }
                
                if(ch != '\\'){
                    unionHelper(4 * bno + 0, 4 * bno + 3);
                    unionHelper(4 * bno + 1, 4 * bno + 2);
                }
                
                if(i > 0){
                    int obno = (i - 1) * grid.size() + j;
                    unionHelper(4 * bno + 0, 4 * obno + 2);
                }
                
                if (j > 0){
                    int obno = i * grid.size() + (j - 1);
                    unionHelper(4 * bno + 3, 4 * obno + 1);
                }
                
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i)count++;
        }
        return count;
    }
};