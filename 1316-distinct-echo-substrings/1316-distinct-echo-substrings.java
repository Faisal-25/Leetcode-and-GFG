class Solution {
    public int distinctEchoSubstrings(String text) {
        HashSet<String> s = new HashSet<>();
        int cnt  = 0;
        int n = text.length();
        for(int len = 1;len<=n/2;len++){
            cnt = 0;
            for(int l = 0,  r = len;r<n;l++,r++){
                if(text.charAt(l) == text.charAt(r)){
                    cnt++;
                }else{
                    cnt = 0;
                }
                if(cnt == len){
                    String str = text.substring(l,r+1);
                    // cout<<str<<endl;
                    s.add(str);
                    cnt--;
                }
            }
        }
        return s.size();
    }
}