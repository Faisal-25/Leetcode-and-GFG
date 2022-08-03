class Solution {
public:
    int power(int n){
        int steps = 0;
        while(n>1){
            if(n%2 == 1){
                n =n*3 + 1;
            }
            else{
                n/=2;
            }
            steps++;
        }
        return steps;
    }
  int getKth(int lo, int hi, int k) {
       
        vector<pair<int,int>> v;
        for(int i = lo;i<=hi;i++){
           v.push_back({power(i),i});
            
        }
       sort(v.begin(),v.end());
        return v[k-1].second;
  }
        
};