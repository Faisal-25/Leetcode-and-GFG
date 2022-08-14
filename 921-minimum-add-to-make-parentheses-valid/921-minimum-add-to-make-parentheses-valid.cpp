class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int exc = 0;
       for(int i = 0;i<s.size();i++){
           if(s[i] == '('){
               st.push(s[i]);
           }
           else if(s[i] == ')'){
               if(st.size() == 0){
                   exc++;
               }
               else{
                   st.pop();
               }
           }
       }
        return exc+st.size();
    }
};