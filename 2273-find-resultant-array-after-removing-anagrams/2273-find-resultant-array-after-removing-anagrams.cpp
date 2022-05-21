class Solution {
public:
    bool areAnagrams(string s1,string s2){
        if(s1.size()!=s2.size())return false;
        vector<int> arr(26);
        for(char ch:s1){
            arr[ch-'a']++;
        }
        for(char ch:s2){
            arr[ch-'a']--;
        }
        for(int val:arr){
            if(val)return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 0;
        int j = 1;
        vector<string> ans;
        while(j<words.size()){
            if(areAnagrams(words[i],words[j])){
                 words[j] = "";
                j++;
            }
            else{
                ans.push_back(words[i]);
                i = j;
                j++;
                
            }
          
        }
        ans.push_back(words[i]);
        return ans;
    }
};