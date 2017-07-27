class Solution {
public:
    //very similar to word break ii
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void helper(string s, vector<string>& out, vector<vector<string>>& res, int idx, vector<bool>& dp) {
        if(idx == s.length()) {
            res.push_back(out);
            return;
        }
        for(int i = idx; i < s.length(); ++i) {
            string tmp = s.substr(idx, i - idx + 1);
            if(isPalindrome(tmp) && dp[i]) {
                int size = res.size();
                out.push_back(tmp);
                helper(s, out, res, i + 1, dp);
                if(res.size() == size) //no solution found
                    dp[i] = false;
                out.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<bool> dp(s.length(), true);
        vector<string> out;
        helper(s, out, res, 0, dp);
        return res;
    }
};
