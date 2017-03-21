class Solution {
public:
    void helper(vector<int> nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
        }
        for (int j = i; j < nums.size(); ++j) {
            if (j == i || nums[i] != nums[j]) { //if (j == i || nums[i] != nums[j]) !
                swap(nums[i], nums[j]);
                helper(nums, i + 1, res);
                //swap(nums[i], nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPerm;
        sort(nums.begin(), nums.end()); //sort
        helper(nums, 0, allPerm);
        return allPerm;  
    }
};

//the idea is similar to generate next permutation?
