class Solution {
    public String truncateSentence(String s, int k) {
        int count = 0;
        String ans = "";
        for(char c:s.toCharArray()){
           if(c == ' '){
                count++;
                if(count == k)return ans;
            }
            ans+=c;
            
            
            
        }
        return ans;
    }
}