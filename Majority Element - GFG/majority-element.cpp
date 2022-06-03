// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    bool isValid(int a[],int n,int val){
        int freq = 0;
        for(int i = 0;i<n;i++){
            int num = a[i];
             freq+=num == val?1:0;
        }
        return freq>n/2;
    }
    int majorityElement(int a[], int n)
    {
        int count = 1;
        int val =a[0];
        for(int i = 0;i<n;i++){
            if(a[i] == val)count++;
            else count--;
            if(count == 0){
                val = a[i];
                count = 1;
            }
        }
       return isValid(a,n,val)?val:-1;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends