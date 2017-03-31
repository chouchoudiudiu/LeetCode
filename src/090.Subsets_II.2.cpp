class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int> output, int curIdx) { //use output, no & since no pop_back()
        if (curIdx == nums.size()) {
            res.push_back(output);
            return;
        }
        int nextPos = curIdx;
        while (nextPos < nums.size() && nums[curIdx] == nums[nextPos])
            ++nextPos;
        helper (nums, res, output, nextPos);
        output.push_back(nums[curIdx]);
        helper (nums, res, output, curIdx + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> output;
        helper(nums, res, output, 0);
        return res;
    }
};
