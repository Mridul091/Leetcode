class NumMatrix {
public:
    vector<vector<int>> matrix1;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        matrix1 = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                matrix1[i][j] = matrix1[i-1][j] + matrix1[i][j-1] - matrix1[i-1][j-1] + matrix[i-1][j-1];
                // cout << matrix1[i][j] << " ";
             }
            // cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // row1++, col1++, row2++, col2++;
        return matrix1[row2+1][col2+1] - matrix1[row1][col2+1] - matrix1[row2+1][col1] + matrix1[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */