class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& output, int n, int k, int start) {
        if (output.size() == k) {
            res.push_back(output);
            return;
        }
        for (int i = start; i <= n; ++i) {
            output.push_back(i);
            helper(res, output, n, k, i + 1); //用start+1就不对，会出现4,3或者重复的，回头路了
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> output;
        helper(res, output, n, k, 1);
        return res;
    }
};
