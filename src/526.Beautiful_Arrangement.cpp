class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for(int i = 0; i < N; ++i)
            nums[i] = i + 1;
        return helper(nums, N);
    }
    int helper(vector<int>& nums, int n) {
        if(n <= 0)
            return 1;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(n%nums[i] == 0 || nums[i]%n == 0) {
                swap(nums[i], nums[n - 1]);
                res += helper(nums, n - 1);
                swap(nums[i], nums[n - 1]);
            }
 
        }
        return res;
    }
};
2 4 3 1 
4 2 3 1 
3 4 1 2 
4 1 3 2 
1 4 3 2 
3 2 1 4 
2 1 3 4 
1 2 3 4
//nums[n - 1] 存着n, 与之前i, j swap不同，这样保持相对顺序，把确认好的丢一边
