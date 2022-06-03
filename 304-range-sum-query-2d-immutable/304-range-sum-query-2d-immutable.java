class NumMatrix {
    int [][]m = new int[0][0];
    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        this.m = new int[n+1][m+1];
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                this.m[i][j] = matrix[i-1][j-1]+this.m[i-1][j]+this.m[i][j-1]-this.m[i-1][j-1];
            }
        }
    }
    
 
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return this.m[row2+1][col2+1]-this.m[row1][col2+1] - this.m[row2+1][col1]+this.m[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */