class Solution {
    static class pair{
        int i;
        int j;
        int level;
        pair(int i,int j,int level){
            this.i = i;
            this.j = j;
            this.level = level;
        }
    }
    public void dfs(int [][]grid,int i,int j,int [][] visited, ArrayDeque<pair> q){
        if(i < 0 || j < 0 || i>=grid.length || j>=grid[0].length || visited[i][j] == 1 || grid[i][j] == 0){
            return;
        }
        visited[i][j] = 1;
        pair p = new pair(i,j,0);
        q.add(p);
        dfs(grid,i+1,j,visited,q);
        dfs(grid,i-1,j,visited,q);
        dfs(grid,i,j+1,visited,q);
        dfs(grid,i,j-1,visited,q);
        
    }
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        if(n == 0)return 0;
        int m = grid[0].length,j1,i1;
        int [][] visited = new int[grid.length][grid[0].length];
       ArrayDeque<pair> q = new ArrayDeque<>();
        boolean flag = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]== 1){
                   flag = true;
                    dfs(grid,i,j,visited,q);
                    break;
                }
            }
            if(flag)break;
        }
       
  
        while(!q.isEmpty()){
            pair p = q.remove();
            int i = p.i;
            int j = p.j;
            int lvl = p.level;
            if(visited[i][j] == 2)continue;
            if(visited[i][j]!=1 && grid[i][j] == 1){
                return lvl-1;
            }
            visited[i][j] = 2;
            addNeighbour(i-1,j,q,visited,grid,lvl);
            addNeighbour(i+1,j,q,visited,grid,lvl);
            addNeighbour(i,j-1,q,visited,grid,lvl);
            addNeighbour(i,j+1,q,visited,grid,lvl);
        }
   
    
    
    
    return -1;
    
    }
        void addNeighbour(int i,int j,ArrayDeque<pair> q,int[][]visited,int[][]grid,int lvl){
            if(i>=0 && j>=0 && i<grid.length && j<grid[0].length && visited[i][j]!=1 && visited[i][j]!=2){
                q.add(new pair(i,j,lvl+1));
            }
            return;
        }

























}