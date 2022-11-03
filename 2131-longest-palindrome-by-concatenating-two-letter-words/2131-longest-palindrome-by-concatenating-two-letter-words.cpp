class Solution {
public:
    string swap(string s){
        char temp = s[0];
        s[0] = s[1];
        s[1] = temp;
        return s;
    }
    bool isPalindrome(string &s){
        return s[0] == s[1];
    }
    int longestPalindrome(vector<string>& words) {
        int len = 0;
       unordered_map<string, int> m;
        int unpaired = 0;
        for(int i = 0;i<words.size();i++){
           if(isPalindrome(words[i])){
               if(m[words[i]]>0){
                   unpaired--;
                   len+=4;
                   m[words[i]]--;
               }else{
                   m[words[i]]++;
                   unpaired++;
               }
           }
           else{
               string rev = swap(words[i]);
               if(m[rev]>0){
                   len+=4;
                   m[rev]--;
               }else{
                   m[words[i]]++;
               }
           } 
           
        }
        if(unpaired>0){
            return len+=2;
        }
        return len;
    }
};