class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int n = command.size();
        for(int i = 0;i<n;){
            if(command[i] == 'G'){
                ans+="G";
                i++;
            }
            else if(command[i] == '(' && command[i+1] == ')'){
                ans+="o";
                i+=2;
            }
            else{
                ans+="al";
                i+=4;
            }
        }
        return ans;
    }
};