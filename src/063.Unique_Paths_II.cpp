class Solution {
public:
    int uniquePathsWithObstacles (vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())   
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        mat[m - 1][n - 1] = 1;//initialization!
        for (int i = m - 2; i >= 0; --i)
            mat[i][n - 1] = obstacleGrid[i][n - 1] == 1 ? 0 : mat[i + 1][n - 1];
        for (int j = n - 2; j >= 0; --j)
            mat[m - 1][j] = obstacleGrid[m - 1][j] == 1 ? 0 : mat[m - 1][j + 1];
        
        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j) {
                mat[i][j] = obstacleGrid[i][j] == 1? 0:mat[i + 1][j] + mat[i][j + 1];
        }
    
        return mat[0][0];
    }

};
