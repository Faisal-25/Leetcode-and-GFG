class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bs;
        for(int i = 0;i<bank.size();i++){
            bs.insert(bank[i]);
        }
        unordered_set<string> vms;
        queue<string> q;
        q.push(startGene);
        vms.insert(startGene);
        int lvl = 0;
        string choices = "ACGT";
        while(q.empty() == false){
            
            int sz = q.size();
            
            while(sz--){
                string top = q.front();
                q.pop();
                if(top == endGene){
                    return lvl;
                }
                string temp = top;
                cout<<temp<<endl;
                for(int i = 0;i<top.size();i++){
                    for(char c:choices){
                        temp[i] = c;
                        if(vms.find(temp) == vms.end() && bs.find(temp)!=bs.end()){
                            q.push(temp);
                            vms.insert(temp);
                        }
                    }
                    temp = top;
                }
                
            }
            lvl++;
        }
        return -1;
    }
};