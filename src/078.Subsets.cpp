class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int> output, int i) {
        if (i == nums.size()) {
            res.push_back(output);
            return;
        }
        helper(res, nums, output, i + 1);
        output.push_back(nums[i]);
        helper(res, nums, output, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        helper(res, nums, output, 0);
        return res;
    }
};


====
    class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& sol, int index, vector<int>& nums) {
        if(index == nums.size()) {
            res.push_back(sol);
            return;
        }
        helper(res, sol, index + 1, nums);
        sol.push_back(nums[index]);
        helper(res, sol, index + 1, nums);
        sol.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        helper(res, sol, 0, nums);
        return res;
    }
};
