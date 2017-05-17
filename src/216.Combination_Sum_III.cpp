class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& output, int index, int k, int n) {
        if (n < 0)
            return;
        if (output.size() == k && n == 0) {
            res.push_back(output); //return or not both ok
            return; //return since adding more item to output the size will not be k
        }
        for (int i = index; i <= 9; ++i) {
            output.push_back(i);
            dfs(res, output, i + 1, k, n - i);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> output;
        dfs(res, output, 1, k, n);
        return res;
    }
};
