class Solution {
    public:
    int numSplits(string s) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        int* pre = new int[s.size()];
        int* post = new int[s.size()];
        for(int i = 0;i<s.size();i++){
            s1.insert(s[i]);
            pre[i] = s1.size();
        }
        for(int i = s.size() -1 ;i>=0;i--){
            s2.insert(s[i]);
            post[i] = s2.size();
        }
        int ans = 0;
        for(int i = 0;i<s.size()-1;i++){
            ans += pre[i] == post[i+1]?1:0;
        }
        return ans;
    }
};