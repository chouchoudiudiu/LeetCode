class Solution {
public:
    void helper(vector<int>& num, int i, vector<vector<int>>& res) {
        if (i == num.size()) {
            res.push_back(num);
        }
        for (int j = i; j < num.size(); ++j) {
            swap(num[i], num[j]);
            helper(num, i + 1, res);
            swap(num[i], num[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> allPerm;
        helper(num, 0, allPerm);
        return allPerm;    
    }
};
