class Solution {
  public  boolean solve(String o,String f){
        if(f.length()<o.length())return false;
        int i = 0;
        int j = 0;
        while(i<o.length()&&j<f.length()){
            if(o.charAt(i)!=f.charAt(j)){
                if(i>0 && o.charAt(i-1) == f.charAt(j)){
                    
            		j++;
       			 }
                else{
                    return false;
                }
            }
            else{
                i++;
                j++;
            }
        }
        while(j<f.length()){
            if(o.charAt(i-1)!=f.charAt(j)){
                return false;
            }
			j++;
        }
        return i == o.length();
    }

    public boolean isLongPressedName(String name, String typed) {
        return solve(name,typed);
    }
}