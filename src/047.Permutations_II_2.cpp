class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, int i) {
        if (i == nums.size()) {
            res.push_back(nums);
        }
        unordered_set<int> used;
        for (int j = i; j < nums.size(); ++j) {
            if (used.find(nums[j]) == used.end()) {
                swap(nums[i], nums[j]);
         		helper(nums, res, i + 1);
          		swap(nums[i], nums[j]);
          		used.insert(nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPerm;
        helper(nums, allPerm, 0);
        return allPerm;  
    }
};
