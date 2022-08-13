class Solution {
public:
    string find(unordered_map<string,string>&parent,unordered_map<string,double>&factor,string s){
        if(parent.find(s) == parent.end()){
            parent[s] = s;
            factor[s] = 1.0;
           
            return s;
        }
        if(parent[s] == s){
            cout<<1<<endl;
            return s;
        }
        
        string lastP = parent[s];
       string p = find(parent,factor,lastP);
        parent[s] = p;
        factor[s] = factor[s]*factor[lastP];
        return p;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(queries.size());
        unordered_map<string,string> parent;
        unordered_map<string,double> factor;
        int k = 0;
        for(vector<string> equation:equations){
            string p1 = find(parent,factor,equation[0]);
            string p2 = find(parent,factor,equation[1]);
            parent[p1] = p2;
            factor[p1] = factor[equation[1]]*values[k]/factor[equation[0]];
            cout<<factor[p1]<<endl;
            k++;
        }
        for(int i = 0;i<queries.size();i++){
            string s1 = queries[i][0];
            string s2 = queries[i][1];
           
            if(parent.find(s1) == parent.end() || parent.find(s2) == parent.end()){
                ans[i] = -1.0;
                continue;
            }
            // cout<<find(parent,factor,s1)<<" "<<find(parent,factor,s2)<<endl;
            if(find(parent,factor,s1)!=find(parent,factor,s2)){
                ans[i] = -1.0;
                continue;
            }
              cout<<s1<<factor[s1]<<" "<<s2<<factor[s2]<<endl;
            ans[i] = (double)(factor[s1])/factor[s2];
        }
        return ans;
    }
};