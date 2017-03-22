class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;
        int m = nums[0], i = 0;
        while (i <= m) { //m is the rightest index can reach so far
            m = max(m, i + nums[i]);
            if (m >= n - 1)
                return true;
            ++i;
        }
        return m >= n - 1;
    }
};
