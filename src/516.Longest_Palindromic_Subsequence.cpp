class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0)); //start point, end point
        for(int i = n - 1; i >= 0; --i) {//因为dp i需要依赖dp i + 1状态，所以从后往前求,最后求到 i = 0
            dp[i][i] = 1;
            for(int j = i + 1; j <= n - 1; ++j) {//j则是从(i的右侧)i + 1开始，一直到n，每个状态依赖于j - 1
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

//space can be optimized further
