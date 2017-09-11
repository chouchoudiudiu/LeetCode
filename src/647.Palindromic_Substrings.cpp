class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), cnt = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int j = 0; j < n; ++j) {
            dp[j][j] = true;
            ++cnt;
            for(int i = 0; i < j; ++i) {//i可以从0取到j - 1
                if((i + 1 >= j - 1 || dp[i + 1][j - 1]) && s[i] == s[j]) {
                    dp[i][j] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
//important to add i + 1 >= j - 1 比如 ttabad j = 4; 其中aba这段，i = 2时候, i + 1 == j - 1 = 3 得出aba这段满足；如果是 taab; j = 2, i = 1时候，
//i + 1 = 2, j - 1 = 1 cross!
