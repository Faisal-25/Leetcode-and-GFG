class Solution {
public:
    string next_permutation(string s){
        int i = s.size() - 1;
        while(i>0 && s[i-1]>=s[i])i--;
        if(i == 0)return "";
        int j = s.size() - 1;
        while(j>0 && s[j]<=s[i-1])j--;
        char temp = s[j];
        s[j] = s[i-1];
        s[i-1] = temp;
        reverse(s.begin()+i,s.end());
        return s;
        
    }
    int nextGreaterElement(int n) {
    string s = to_string(n);
    
    string s1 = next_permutation(s);
    if(s1 == "")return -1;
       long next = stol(s1);
        return next == n || next > INT_MAX ? -1 : next;
}
};