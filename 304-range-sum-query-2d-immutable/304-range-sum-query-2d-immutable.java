class NumMatrix {
    int [][]m = new int[0][0];
    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        this.m = new int[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                this.m[i][j] = matrix[i][j];
            }
        }
    }
    
 
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if(Math.abs(row2-row1)<this.m.length&&Math.abs(col1-col2)<this.m[0].length){
          for(int i = row1;i<=row2;i++){
              for(int j = col1;j<=col2;j++){
                  sum+=this.m[i][j];
              }
          }
            
        }
        return sum;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */