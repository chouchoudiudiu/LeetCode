class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int side = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //dp[i][j] represents max square ending at position (i-1, j-1)
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    side = max(side, dp[i][j]);
                }
            }
        }
        return side*side; 
    }
};

/*
*** 0 1 2
*** 3 4 5
*** 6 7 8 位置上，计算到以4结尾假设dp4 == dp5 == dp7 == 2, 则0134都是1,1245都是1,3467都是1，则加上8变成3*3 valid
*/
