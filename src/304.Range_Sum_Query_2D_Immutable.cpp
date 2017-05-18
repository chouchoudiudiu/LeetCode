class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i <= m; ++i) {
            vector<int> tmp(n + 1, 0);
            sums.push_back(tmp);
        }
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { //row1,col1相关的不用加1
        if (sums.empty())
            return 0;
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
   
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
