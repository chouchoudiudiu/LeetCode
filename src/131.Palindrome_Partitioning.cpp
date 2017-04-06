class Solution {
public:
//similar to word break ii
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l++] != s[r--]) 
                return false;
        }
        return true;
    }
    void dfs(string s, vector<string>& output, int index, vector<bool>& dp, vector<vector<string>>& res) {
        if (index == s.length()) {
            res.push_back(output);
            return;
        }
        for (int i = index; i < s.length(); ++i) {
            string tmp = s.substr(index, i - index + 1);
            if (isPalindrome(tmp) && dp[i + 1]) {
                output.push_back(tmp);
                int size = res.size();
                dfs(s, output, i + 1, dp, res);
                if (size == res.size()) //no solution found
                    dp[i + 1] = false;
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> output;
        vector<bool> dp (s.length() + 1, true); //initialized as true
        dfs(s, output, 0, dp, res);
        return res;
    }
};
