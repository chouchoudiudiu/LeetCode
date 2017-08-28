class Solution {
public:
    int helper(int n, vector<int>& nums) {
        if(nums[n] != -1)
            return nums[n];
        int cnt = 0;
        for(int i = 1; i <= n; ++i) 
            cnt += helper(i - 1, nums)*helper(n - i, nums);
        nums[n] = cnt;
        return cnt;
    }
    int numTrees(int n) {
        vector<int> nums(n + 1, -1);
        nums[0] = 1;
        nums[1] = 1;
        return helper(n, nums);
    }
};

//each number act as root
//TLE
