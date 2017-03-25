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
