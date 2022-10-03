class Solution {
    public int lengthOfLastWord(String s) {
      int i = s.length()-1;
        while(s.charAt(i) == ' '){
            i--;
        }
        int count = 0;
        for(;i>=0;i--){
            if(s.charAt(i) == ' '){
                return count;
            }else{
                count++;
            }
        }
        return count;
    }
}