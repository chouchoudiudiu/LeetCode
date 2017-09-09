class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        return max(rob(nums, 1, n - 1), rob(nums, 0, n - 2));
    }
    int rob(vector<int>& nums, int left, int right) {
        if(left == right) //if only one item left
            return nums[left];
        vector<int> dp(right + 1, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for(int i = left + 2; i <= right; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[right];
    }
};
//123 if 
/*       旧写法是错的 if(right - left <= 1)
            return nums[left]; wrong*/
//如果我们把第一家和最后一家分别去掉，各算一遍能抢的最大值，然后比较两个值取其中较大的一个即为所求。
