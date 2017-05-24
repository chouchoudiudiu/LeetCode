class Solution {
public:
//similar to word break
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() <= 2)
            return {};
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            int len = word.length();
            if (len == 0)
                continue;
            vector<bool> dp(len + 1, false);
            dp[0] = true;
            for (int i = 1; i <= len; ++i) //i: number of char involved
                for (int j = 0; j < i; ++j) {
                    string tmp = word.substr(j, i - j);  //j: previous number of chars
                    if (tmp != word && dp[j] && dict.count(tmp)) {//not including self
                        dp[i] = true;
                        break;
                    }
                }
            if(dp.back())   //if reaches full length
                res.push_back(word);
        }
        return res;
    }
};
