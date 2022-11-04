class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        string temp = "";
        for(int i = n-1;i>=0;i--){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U'){
                temp+=s[i];
            }
        }
        int k = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U'){
                s[i] = temp[k];
                k++;
            }
        }
        return s;
    }
};