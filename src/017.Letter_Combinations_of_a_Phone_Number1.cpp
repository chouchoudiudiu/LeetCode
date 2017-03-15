class Solution {
public:
    vector<string> keys = {"", "", "abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        res.push_back("");
        for (int i = 0; i < digits.length(); ++i) {
            vector<string> newRes;
            string letters = keys[digits[i] - '0'];
            for (int j = 0; j < res.size(); ++j)
                for (int k = 0; k < letters.length(); ++k) {
                    newRes.push_back(res[j] + letters[k]);
                }
            res = newRes;
        }
        
        return res;
    }
};
