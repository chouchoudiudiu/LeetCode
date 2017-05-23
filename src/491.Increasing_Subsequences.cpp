class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> output;
        set<vector<int>> res; //可以去重，not unordered_set, 无hash (key为vector<int>)
        helper (nums, output, res, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
    
    void helper (vector<int>& nums, vector<int>& output, set<vector<int>>& res, int start) {
        if (output.size() >= 2 )//&& start >= nums.size()) //no need the later part!
            res.insert(output);

        for (int i = start; i < nums.size(); ++i) {
            if (output.size() == 0 || (nums[i] >= output.back())) {
                output.push_back(nums[i]);
                helper(nums, output, res, i + 1); //not start + 1
                output.pop_back();
            }
        }
    }
};
