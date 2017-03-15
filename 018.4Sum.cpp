class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        res.insert({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                    }
                    else if (sum < target)
                        ++k;
                    else
                        --l;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
