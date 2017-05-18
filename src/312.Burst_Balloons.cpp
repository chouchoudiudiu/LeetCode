class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0)); //nums.size(), not N 打爆区间[i,j]中的所有气球能得到的最多金币
        //find which balloon to burst LAST will give us the most coins for that subinterval
        for (int len = 1; len <= N; ++len)
            for (int left = 1; left <= N - len + 1; ++left) {
	            int right = left + len - 1;
	            for (int k = left; k <= right; ++k) {
		            dp[left][right] = max(dp[left][right], nums[left - 1]*nums[k]*nums[right + 1] +
				                                            dp[left][k - 1]  + dp[k + 1][right]);
                //k是[left, right]最后剩下的气球，炸它时它的邻居确定，是[left - 1]和[right + 1]，再加上之前的左右两段和
	                }
            }
        return dp[1][N];    
    }
};
