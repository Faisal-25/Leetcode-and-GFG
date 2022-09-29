class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String [] arr1 = s1.split(" ");
        String [] arr2 = s2.split(" ");
        HashMap<String, Integer> m = new HashMap<>();
        for(int i = 0;i<arr1.length;i++){
            m.put(arr1[i], m.getOrDefault(arr1[i], 0)+1);
        }
         for(int i = 0;i<arr2.length;i++){
            m.put(arr2[i], m.getOrDefault(arr2[i], 0)+1);
        }
        String ans = "";
        for(String s:m.keySet()){
            if(m.get(s) == 1){
                ans+=s +" ";
            }
        }
        if(ans.length() == 0){
            return new String[0];
        }
        return ans.split(" ");
    }
}