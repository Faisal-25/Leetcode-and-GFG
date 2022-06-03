class Solution {
public:
      bool isValid(vector<int>&a,int n,int val){
        int freq = 0;
        for(int i = 0;i<n;i++){
            int num = a[i];
             freq+=num == val?1:0;
        }
        return freq>n/2;
    }
    int majorityElement(vector<int>& a,int n = 0) {
       //  n = a.size();
       //  int count = 1;
       //  int val =a[0];
       //  for(int i = 0;i<n;i++){
       //      if(a[i] == val)count++;
       //      else count--;
       //      if(count == 0){
       //          val = a[i];
       //          count = 1;
       //      }
       //  }
       // return isValid(a,n,val)?val:-1;
        unordered_map<int,int> m;
        for(int val:a){
            m[val]++;
        }
        for(auto&[k,v]:m){
            if(m[k]>a.size()/2)return k;
        }
        return -1;
    }
};