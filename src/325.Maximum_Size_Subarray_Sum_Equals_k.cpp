class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m; //.first, the cumSum so far; .second, where the cumSum first appears
        int maxLen = 0;
        int cumSum = 0;
        m[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            cumSum += nums[i];
            if (m.find(cumSum - k) != m.end())
                maxLen = max(maxLen, i - m[cumSum - k]);
            if (m.find(cumSum) == m.end()) //otherwise keep the original one, which is more left
                m.insert({cumSum, i});
        }
        return maxLen;
    }
};
