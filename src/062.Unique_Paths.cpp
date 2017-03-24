class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1)
            return 0;
        vector<vector<int>> mat(m, vector<int>(n, 1));
        for (int i = 1; i <= m - 1; ++i)
            for (int j = 1; j <= n - 1; ++j) {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
            }

        return mat[m - 1][n - 1];
    }
};

//memory O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1)
            return 0;
        vector<int> dp(n, 1);
        for (int i = 1; i <= m - 1; ++i)
            for (int j = 1; j <= n - 1; ++j) {
                dp[j] += dp[j - 1]; //一行一行的扫，算到第二行时候，用第一行该列的值加上第二行左边于该列的值
            }

        return dp[n - 1];
    }
};
