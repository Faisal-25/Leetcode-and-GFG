class Solution {
public:
    string reverseVowels(string s) {
                int i = 0;
        int j = s.length() - 1;
        while(i<j){
            char c = s[i];
            while(!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] =='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') && i<j){
                i++;
            }
            c = s[j];
            while(!(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] ==    'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U') && i<j){
                j--;
            }
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        return s;
    }
};