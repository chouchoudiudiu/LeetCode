class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) 
            return true;
        int m = nums[0], i = 0, n = nums.size() - 1;
        while (i <= m) { //m is the rightest index can reach so far
            m = max(m, i + nums[i]);
            if (m >= n)
                return true;
            ++i;
        }
        return m >= n;
    }
};
