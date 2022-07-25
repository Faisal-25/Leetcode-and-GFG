class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        cout<<s.size()<<endl;
        for(int i = 0;i<s.size();i++){
            m[s[i]]++;
        
        }
        int maxOdd = 0;
        int maxPal = 0;
        for(auto &[k,v]:m){
            cout<<v<<" ";
            if(v%2 == 1){
                maxPal+=(v-1);
                maxOdd = max(maxOdd,v);
                
            }
            else{
                maxPal +=v;
                
            }
        }
        if(maxOdd !=0){
        return maxPal+1;
        }
        return maxPal;
    }
    
};