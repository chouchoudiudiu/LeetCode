class Solution {
public:
    void helper(string s, vector<string>& res, int left, int right, int n) {
        if (s.length() == 2*n) {
            res.push_back(s);
            return;
        }
        if (left < n) 
            helper (s + '(', res, left + 1, right + 1, n);
        if (right > 0)
            helper (s + ')', res, left, right - 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", res, 0, 0, n); //number of left used, number of right available, right must come after left
        return res;
    }
};
