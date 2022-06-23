class Solution {
      static int [] parent = new int[0];
      static int [] rank = new int[0];
    public static int findParent(int v){
        if(parent[v] == v)return v;
        return parent[v] = findParent(parent[v]);
    }
    public static void union(int v1,int v2){
        if(rank[v1]>rank[v2]){
            parent[v2] = v1;
        }
        else if(rank[v2]>rank[v1]){
            parent[v1] = v2;
        }
        else{
            parent[v2] = v1;
            rank[v1]++;
        }
    }
    public int[] findRedundantConnection(int[][] edges) {
        parent = new int[edges.length+1];
        rank = new int[edges.length+1];
        for(int i = 0;i<parent.length;i++){
            parent[i] = i;
        }
        for(int[]edge:edges){
            
            int p1 = findParent(edge[0]);
            int p2 = findParent(edge[1]);
            if(p1 == p2){
                return new int[]{edge[0],edge[1]};
            }
            else{
                union(p1,p2);
            }
        }
        return new int[]{-1};
    }
    
}