// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int> s;
	void dfs(vector<int> adj[],vector<bool> &visited,int src){
	    visited[src] = true;
	    for(int i:adj[src]){
	        if(!visited[i]){
	            dfs(adj, visited,i);
	        }
	    }
	    s.push(src);
	}
	void dfs1(vector<int> adj[],int src, vector<bool>& visited1){
	    visited1[src] = true;
	    for(int i:adj[src]){
	      if(!visited1[i]){
	        dfs1(adj,i,visited1);
	        
	      }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V);
       for(int i = 0;i<V;i++){
           if(!visited[i]){
               dfs(adj,visited,i);
           }
       }
       //we have to take transpose of the graph
     vector<int> tsp[V];
       for(int i = 0;i<V;i++){
          
           for(int j = 0;j<adj[i].size();j++){
              
              tsp[adj[i][j]].push_back(i);
               
           }
        
       }
      
       
       vector<bool> visited1(V);
    
       int count = 0;
       while(!s.empty()){
           int v = s.top();
           s.pop();
     
           if(!visited1[v]){
               dfs1(tsp,v,visited1);
               count++;
           }
       }
       return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends