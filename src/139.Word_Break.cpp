class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= n; ++i) { //i: number of char involved
            for (int j = 0; j < i; ++j) { 
                string str = s.substr(j, i - j);  //j: previous number of chars
                if (dict.count(str) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
