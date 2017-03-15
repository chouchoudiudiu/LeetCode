class Solution {
public:
    vector<string> keys = {"", "", "abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz"};   
    void dfs(string digits, string output, vector<string>& res, int i) {
        if (output.length() == digits.length()) {
            res.push_back(output);
            return;
        }
        string s = keys[digits[i] - '0'];
        for (int j = 0; j < s.length(); ++j) {
            dfs(digits, output + s[j], res, i + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        dfs(digits, "", res, 0);
        return res;
    }
};
