class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
             if(matrix.length == 0) {
            return new LinkedList<>();
        }
        int n = matrix.length;
        int m = matrix[0].length;
        List<Integer> ans = new LinkedList<>();
        int left=0,right=m-1,bottom=n-1,top=0;
        int direction = 1;
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++) ans.add(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) ans.add(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) ans.add(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) ans.add(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return ans;
        
    }
}