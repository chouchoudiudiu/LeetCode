class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0, n = nums.size();
        vector<int> sums(n, 0);
        sums[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            sums[i] = nums[i] + sums[i + 1]; //全正，所以sum表示i以后所有数加起来的最大值
        helper (nums, sums, S, 0, res);
        return res;
    }
    
    void helper(vector<int>& nums, vector<int>& sums, int target, int start, int& res) {
        if (start >= nums.size()) {
            if(target == 0)
                ++res;
            return;
        }
        if (sums[start] < abs(target)) //abs
            return;
        helper(nums, sums, target + nums[start], start + 1, res);
        helper(nums, sums, target - nums[start], start + 1, res);
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        helper(nums, S, 0, res);
        return res;
    }
    
    void helper(vector<int>& nums, int target, int start, int& res) {
        if(start >= nums.size()) {
            if(target == 0)
                ++res;
            return;
        }
        helper(nums, target + nums[start], start + 1, res);
        helper(nums, target - nums[start], start + 1, res);
    }
};
