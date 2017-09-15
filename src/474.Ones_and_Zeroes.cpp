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
  // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
    // from the first few strings up to the current string s
    // Catch: have to go from bottom right to top left
    // Why? If a cell in the memo is updated(because s is selected),
    // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
    // If we go from top left to bottom right, we would be using results from this iteration => overcounting
