class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //dp[i][j]表示有i个0和j个1时能组成的最多字符串的个数
        for (auto s : strs) {
            int zeros = countZeros(s);
            int ones = s.length() - zeros;  
            for (int i = m; i >= zeros; --i) 
                for (int j = n; j >= ones; --j) { //from m to zeros
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
        }
        return dp[m][n];
    }
    int countZeros(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '0')
                ++cnt;
        }
        return cnt;
    }
};
/*
choosing to put this string in any of the subset possible by using the previous strings traversed so far will impact the element denoted by dp[i][j] for i and j satisfying zeros<=i<=m, ones<=j<=n 这里面才有足够的0和1可以放 profitable?
*/
