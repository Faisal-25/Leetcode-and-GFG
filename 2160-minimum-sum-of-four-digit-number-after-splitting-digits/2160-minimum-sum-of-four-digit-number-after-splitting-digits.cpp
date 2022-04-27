class Solution {
public:
    int minimumSum(int num) {
        string n = to_string(num);
        sort(n.begin(),n.end());
        string fh = n.substr(0,2);
        string sh = n.substr(2,2);
        //swap fh[1] and sh[0];
        char temp = fh[1];
        fh[1] = sh[0];
        sh[0] = temp;
        return stoi(fh)+stoi(sh);
        
    }
};