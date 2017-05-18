class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        mat.resize(m + 1, vector<int>(n + 1, 0));
        bit.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                update(i, j, matrix[i][j]);
            }
    }
    
    void update(int row, int col, int val) {
        int diff = val - mat[row + 1][col + 1];
        for (int i = row + 1; i < bit.size(); i += (i & -i))
           for (int j = col + 1; j < bit[i].size(); j += (j & -j)) {
               bit[i][j] += diff;
           } 
        mat[row + 1][col + 1] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) + getSum(row1, col1) - getSum(row2 + 1, col1) - getSum(row1, col2 + 1);
    }
    
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= (i & -i))//top down
            for (int j = col; j > 0; j -= (j & -j)) {
                res += bit[i][j];
            }
        return res;
    }
    
    vector<vector<int>> mat;
    vector<vector<int>> bit;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
