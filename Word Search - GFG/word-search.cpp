//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(vector<vector<char>> &matrix,int i,int j,vector<vector<int>> &vis,bool &ans,string &temp,int idx){
    if(temp.length()==idx) {
        ans=true;
        return;
    }
    if(ans or i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size() or vis[i][j]) return;
    if(matrix[i][j]!=temp[idx]){
        return;
    }

    if(matrix[i][j]==temp[idx]) idx+=1;
        vis[i][j]=1;
    dfs(matrix,i-1,j,vis,ans,temp,idx);
    // dfs(matrix,i-1,j+1,vis,ans,temp,idx);
    dfs(matrix,i,j+1,vis,ans,temp,idx);
    // dfs(matrix,i+1,j+1,vis,ans,temp,idx);
    dfs(matrix,i+1,j,vis,ans,temp,idx);
    // dfs(matrix,i+1,j-1,vis,ans,temp,idx);
    dfs(matrix,i,j-1,vis,ans,temp,idx);
    // dfs(matrix,i-1,j-1,vis,ans,temp,idx);
    vis[i][j]=0;
}
    bool isWordExist(vector<vector<char>>& matrix, string word) {
         int n = matrix.size();
	    int m = matrix[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> res;
        bool flag=false;
        for(int i=0;i<n;i++){
             bool ans=false;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==word[0]){
                   
                    string temp=word;
                    dfs(matrix,i,j,vis,ans,temp,0);
                    if(ans){
                       return true;
                    }
                }
               
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends