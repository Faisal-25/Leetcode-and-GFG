class Solution {
    public boolean judgeCircle(String moves) {
        int [] arr = new int[4];
        for(int i = 0;i<moves.length();i++){
            if(moves.charAt(i) == 'U')arr[0]++;
            else if(moves.charAt(i) == 'L')arr[1]++;
            else if(moves.charAt(i) == 'R')arr[2]++;
            else arr[3]++;
        }
        return arr[0] == arr[3]&&arr[1] == arr[2];
        
    }
}