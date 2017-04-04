class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m <= 0 || n <= 0)   return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = (s[0] == t[0]) ? 1:0;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = (s[i] == t[0]) ? dp[i - 1][0] + 1:dp[i - 1][0];
        }   
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (s[i] != t[j])
                    dp[i][j] = dp[i - 1][j];//用不了s[i]去匹配
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];//可以选择不用s[i], 或者使用s[i]去match t[j]
            }
        
        return dp[m - 1][n - 1];
    }
};
