//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
vector<int> ans;
    void subsetSum(vector<int> arr, int i, int sum,int n){
        if( i == n){
            ans.push_back(sum);
            return;
        }
        subsetSum(arr, i+1, sum+arr[i] , n);
        subsetSum(arr,i+1, sum, n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       subsetSum(arr,0,0,N);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends