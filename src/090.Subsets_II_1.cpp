class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& output, int start) { 
        res.push_back(output);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i] != nums[i - 1]) { //first time, it is always a new number (no duplicated)
                output.push_back(nums[i]); //[subsets(2, 2)] 若是2，3会有单独的[2][3][2,3]，此时只有[2]与[2,2]即[2, subsets[2]] -> [],[2]
                helper (nums, res, output, i + 1);
                output.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> output;
        helper(nums, res, output, 0);
        return res;
    }
};

/*
subsets([1,2,3,4]) = []
                     // push(1)
                     [1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
                     // pop(), push(2)
                     [2, subsets([3,4])]
                     // pop(), push(3)
                     [3, subsets([4])]
                     // pop(), push(4)
                     [4, subsets([])]
                     // pop()
*/
