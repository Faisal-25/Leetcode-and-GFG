class Solution {
public:
    string largestOddNumber(string num) {
        int i = 0,j=num.size()-1,maxSize = 0;
        string ans = "";
        while(j>=0){
            if((num[j]-'0')%2 == 1){
                return num.substr(0,j+1);
            }
            j--; 
        }
        return "";
    }
};