class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int longest = findLCS(word1, word2, m, n);
        return m + n - 2*longest;
    }
    int findLCS(string word1, string word2, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j) {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        return res;
    }
};

//longest common subsequence
