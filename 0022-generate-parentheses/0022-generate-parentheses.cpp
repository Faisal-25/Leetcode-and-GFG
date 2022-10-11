class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        if(n == 1){
            return {"()"};
        }
        getPar(n,0,"");
        return ans;
    }
    void getPar(int n, int m,string str){
        if(n == 0 && m == 0){
            ans.push_back(str);
            return;
        }
        if(n>0){
            getPar(n-1,m+1,str+"(");
        }
        if(m>0){
            getPar(n,m-1,str+")");
        }
    }
};