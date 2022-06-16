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
    public int[][] updateMatrix(int[][] mat) {
        ArrayDeque<pair> q = new ArrayDeque<>();
        int [][] visited = new int[mat.length][mat[0].length];
        int n = mat.length;
        int m = mat[0].length;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.add(new pair(i,j,0));
                }
                visited[i][j] = -1;
            }
        }
        while(q.isEmpty() == false){
            pair p = q.remove();
            if(visited[p.i][p.j] !=-1)continue;
            visited[p.i][p.j] = p.level;
            addN(visited,p.i+1,p.j,q,p.level+1);
            addN(visited,p.i-1,p.j,q,p.level+1);
            addN(visited,p.i,p.j+1,q,p.level+1);
            addN(visited,p.i,p.j-1,q,p.level+1);
        }
        return visited;
    }
    public static void addN(int[][]visited,int i,int j,ArrayDeque<pair> q,int currL){
        if(i>=0&&j>=0&&j<visited[0].length&&i<visited.length&&visited[i][j]==-1){
            q.add(new pair(i,j,currL));
        }
        return;
    }
}