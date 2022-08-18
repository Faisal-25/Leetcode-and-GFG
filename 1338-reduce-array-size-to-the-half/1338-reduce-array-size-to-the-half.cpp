class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        int N = arr.size();
        for(int i = 0;i<N;i++){
            m[arr[i]]++;
        }
        vector<int> s;
        for(auto&[k,v]:m){
            s.push_back(v);
        }
        sort(s.begin(),s.end(),[](const int &v1,const int &v2){
            return v1>v2;
        });
        int count = 0;
        int set = 0;
        for(int num:s){
            count+=num;
            set++;
            if(count>=N/2)return set;
        }
        return -1;
    }
    
};