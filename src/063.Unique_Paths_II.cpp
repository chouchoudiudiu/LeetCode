class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         if (obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i > 0 && j == 0)
                    dp[i][j] = dp[i - 1][j];
                else if (i == 0 && j > 0)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m - 1][n - 1];
    }
};

=======
    class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(size_t i = 1; i < m; ++i) {
            dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
        }
        for(size_t j = 1; j < n; ++j) {
            dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j - 1] : 0;
        }
        for(size_t i = 1; i < m; ++i)
            for(size_t j = 1; j < n; ++j)
                dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i - 1][j] + 
                dp[i][j - 1] : 0;
        return dp[m - 1][n - 1];
    }
};
