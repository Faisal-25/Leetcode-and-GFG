class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            m[arr[i]]++;
        }

        vector<pair<int,int>> ans;
        for(auto &[k,v]:m){
            ans.push_back(make_pair(k,v));
        }
        sort(ans.begin(),ans.end(),[](const pair<int,int>&p1,const pair<int,int>&p2){
            return p1.second>p2.second;
        });
        int set = 0;
        int count = 0;
        for(int i = 0;i<ans.size();i++){
            count+=ans[i].second;
            set++;
            if(count>=n/2)return set;
        }
        return -1;
    }
};