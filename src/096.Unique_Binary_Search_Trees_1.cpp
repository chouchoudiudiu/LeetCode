class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return n;
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int root = 1; root <= i; ++root) {
                int left = nums[root - 1];
                int right = nums[i - root];
                sum += left*right;
            }
            nums[i] = sum;
        }
        return nums[n];
    }
};
