class Solution {
public:
    int countWords(string str)
{
    
    stringstream s(str);
   
    
    string word;
 
    int count = 0;
    while (s >> word)
        count++;
    return count;
}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> mp;
        for(int i = 0;i<messages.size();i++){
            int len = countWords(messages[i]);
            mp[senders[i]]+=len;
        }
        string ans;
        int maxLen = INT_MIN;
        for(auto &[k,v]:mp){
           if(maxLen<mp[k]){
               maxLen = mp[k];
               ans = k;
           } 
           else if(maxLen == mp[k]){
               if(k>ans){
                   ans = k;
               }
           }
        }
        return ans;
    }
};