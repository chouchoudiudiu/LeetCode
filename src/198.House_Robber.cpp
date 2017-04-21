class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int dp[n] = {0};
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); //max money so far, can choose from either one
        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); //select this number or not
        return dp[n - 1];
    }
};
