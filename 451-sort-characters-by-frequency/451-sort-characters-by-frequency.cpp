class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(char c:s)m[c]++;
        vector<pair<char,int>> sv;
        for(auto &[k,v]:m){
            sv.push_back({k,v});
        }
        sort(sv.begin(),sv.end(),[](const pair<char,int> &p1, const pair<char,int>&p2){
            return p1.second>p2.second;
        });
        string ans = "";
       for(int i = 0;i<sv.size();i++){
            for(int j = 0;j<sv[i].second;j++){
                ans+=sv[i].first;
            }           
        }
        return ans;
            
        
        
        
    }
};