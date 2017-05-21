class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> dp(n, 1), parent(n), res;
        sort(nums.begin(), nums.end());
        int maxLen = 1, maxIdx = 0;
        for (int i = 1; i < n; ++i) {
            int jMax = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    jMax = j;
                }   
            }
            parent[i] = jMax;
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        for (int i = 0; i < maxLen; ++i) {
            res.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
