class Solution {
public:
//计算每个bit这n个数在这个bit位置是1的个数，比如说是k，那么剩下n-k是0，有这个bit构成的1的结果一共有k*(n-k)
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int k = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] & (1 << i))
                    ++k;
            }
            cnt += (n - k)*k;
        }
        return cnt;
    }
};
