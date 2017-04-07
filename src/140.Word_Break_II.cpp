class Solution {
public:
    void dfs(string s, unordered_set<string>& dict, string output, int index, vector<string>& res, vector<bool>& dp){
        if (index == s.length()) {
            output.pop_back(); //remove the last " "
            res.push_back(output);
        }
        for (int i  = index; i < s.length(); ++i) {
            string tmp = s.substr(index, i - index + 1);
            if (dict.find(tmp) != dict.end() && dp[i + 1]) { //otherwise no need to check dfs(i+1)
                tmp = output + tmp + ' ';
                int size = res.size();
                dfs(s, dict, tmp, i + 1, res, dp); //pass tmp in deeper dfs, output didn't change
                if(res.size() == size) //no solution found
                    dp[i + 1] = false; 
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (s.empty() || wordDict.empty())
            return res;
        vector<bool> dp (s.length() + 1, true); //initialized as true
        string output;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dfs(s, dict, output, 0, res, dp);
        return res;
    }
};


//这里加上一个possible数组，如同WordBreak I里面的DP数组一样，用于记录区间拆分的可能性
//Possible[i] = true 意味着 [i,n]这个区间上有解*/
