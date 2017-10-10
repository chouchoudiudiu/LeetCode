class Solution {
public:
    void helper(string s, unordered_set<string>& dict, string out, int idx, vector<string>& res, vector<bool>& dp) {
        if(idx == s.length()) {
            out.pop_back(); // remove the last " "
            res.push_back(out);
        }
        for(int i = idx; i < s.length(); ++i) {
            string tmp = s.substr(idx, i - idx + 1);
            if(dict.find(tmp) != dict.end() && dp[i]) {  //otherwise no need to check dfs(i+1)
                int size = res.size();
                helper(s, dict, out + tmp + " ", i + 1, res, dp); //i + 1 not idx + 1
                if(res.size() == size)//no solution found
                    dp[i] = false;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty())
            return {};
        vector<string> res;
        vector<bool> dp(s.length(), true);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        string out;
        helper(s, dict, out, 0, res, dp);
        return res;
    }
};

//这里加上一个possible数组，如同WordBreak I里面的DP数组一样，用于记录区间拆分的可能性
//Possible[i] = true 意味着 [i,n]这个区间上有解*/
class Solution {
public:
    void helper(string s, unordered_set<string>& dict, string out, int idx, vector<string>& res, vector<bool>& dp) {
        if(idx == s.length()) {
            out.pop_back();
            res.push_back(out);
        }
        for(int i = idx; i < s.length(); ++i) {
            string tmp = s.substr(idx, i - idx + 1);
            if(dict.find(tmp) != dict.end() && dp[i + 1]) {
                int size = res.size();
                helper(s, dict, out + tmp + " ", i + 1, res, dp);
                if(res.size() == 1)
                    return;
                if(res.size() == size)
                    dp[i + 1] = false;
            }
        }
    }

        vector<string> wordBreak(string s, vector<string>& wordDict) {
            if(s.empty() || wordDict.empty())
                return {};
            vector<string> res;
            vector<bool> dp(s.length(), true);
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            string out;
            helper(s, dict, out, 0, res, dp);
            return res;
        }
};
