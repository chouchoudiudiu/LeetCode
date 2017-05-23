class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int len = 1; len <= n; ++len) { //len [1, n]
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = s.substr(i, len);
                for (int k = i; k < j; ++k) { //k is between i to j
                    string left = dp[i][k];
                    string right = dp[k + 1][j];
                    if (left.size() + right.size() < dp[i][j].size())
                        dp[i][j] = left + right;
                }
                string tmp = s.substr(i, len), replace = "";
                auto pos = (tmp + tmp).find(tmp, 1); //starting from 1
                if (pos >= len)
                    replace = tmp; //no repeating substr
                else
                    replace = to_string(len/pos) + "[" + dp[i][i + pos - 1] + "]";//not tmp
                if (replace.size() < dp[i][j].size())
                    dp[i][j] = replace;
            }
        }
        
        return dp[0][n - 1];
    }
};
