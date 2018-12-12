class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> out;
        helper(n, 2, out, res);
        return res;
    }
    void helper(int n, int start, vector<int>& out, vector<vector<int>> &res) {
        if (n == 1) {
            if (out.size() > 1) //important, otherwise may contain self
                res.push_back(out);
        } else {
            for (int i = start; i <= n; ++i) { //i <= n
                if (n % i == 0) {
                    out.push_back(i);
                    helper(n / i, i, out, res);
                    out.pop_back();
                }
            }
        }
    }
};
