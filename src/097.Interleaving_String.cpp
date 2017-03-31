class Solution {
public:
       bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool> > dp(n1 + 1, vector<bool> (n2 + 1, false)); 
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i)
            dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];
        for (int i = 1; i <= n2; ++i)
            dp[0][i] = (s2[i - 1] == s3[i - 1]) && dp[0][i - 1];
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
               dp[i][j] = ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j] )||
                          ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1] );
            }
        }
        return dp[n1][n2];
    }
};

/* "aadbbcbcac"
  Ø d b b c a
Ø T F F F F F
a T F F F F F
a T T T T T F
b F T T F T F
c F F T T T T
c F F F T F T
*/



/* recursion, TLE
class Solution {
public:
    bool helper(string s1, string s2, string s3, int ai, int bi, int ci) {
        if (ai == s1.length() && bi == s2.length() && ci == s3.length())
            return true;
        bool tmp1 = false, tmp2 = false;
        if (ai != s1.length() && ci != s3.length() && s1[ai] == s3[ci])
            tmp1 = helper (s1, s2, s3, ai + 1, bi, ci + 1);
        if (!tmp1 && bi != s2.length() && ci != s3.length() && s2[bi] == s3[ci])
            tmp2 = helper (s1, s2, s3, ai, bi + 1, ci + 1);
        return tmp1 || tmp2;
    }
    bool isInterleave(string s1, string s2, string s3) { 
        if (s1.length() + s2.length() != s3.length())
            return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
};
*/
