class Solution {
public:
    string minWindow(string s, string p) {
         vector<int> m(256);
       int count = 0;
       for(int i = 0;i<p.size();i++){
           if(m[p[i]] == 0){
               count++;
           }
           m[p[i]]++;
       }
       int start = 0;
       int i =0,j=0;
       int res = INT_MAX;
    while(j<s.size()){
        m[s[j]]--;
        if(m[s[j]] == 0){
            count--;
        }
        if(count == 0){
            while(count == 0){
                if(res>j-i+1){
                    res = j-i+1;
                    start = i;
                }
                m[s[i]]++;
              
                if(m[s[i]] == 1){
                    count++;
                }
                i++;
            }
            
        }
        j++;
        
    }
    if(res == INT_MAX){
        return "";
    }
    return s.substr(start,res);
    }
};