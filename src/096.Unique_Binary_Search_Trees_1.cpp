class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        nums[1] = 1;
        for(int i = 2; i <= n; ++i) 
            for(int root = 1; root <= i; ++root) {
                nums[i] += nums[root - 1]*nums[i - root]; //left, right
            }
        return nums[n];
    }
};

//each number act as root
//TLE
