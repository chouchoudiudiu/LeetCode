class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())   
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));

        mat[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; --i)
            mat[i][n - 1] = grid[i][n - 1] + mat[i + 1][n - 1]; //one path only
        for (int j = n - 2; j >= 0; --j)
            mat[m - 1][j] = grid[m - 1][j] + mat[m - 1][j + 1];
        
        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j) {
                mat[i][j] = grid[i][j] + min(mat[i + 1][j], mat[i][j + 1]);
        }
    
        return mat[0][0];
    }
};
