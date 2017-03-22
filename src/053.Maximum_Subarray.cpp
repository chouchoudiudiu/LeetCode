class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) 
            return -1;
        int dp = nums[0], maxSum = dp;
        for (int i = 1; i < nums.size(); ++i) {
            dp = max(nums[i], dp + nums[i]); //-1 -3 1 3 -2 when reaching -2, check which is larger
            maxSum = max(maxSum, dp);
        }
        return maxSum;
    }
};
