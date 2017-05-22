class Solution {
public:
    bool checkSplit(vector<int>& nums, int m, long long target) {
        long long sum = 0;
        int cnt = 1; //start with 1
        for (auto v : nums) {
            sum += v;
            if (sum > target) {
                sum = v;
                ++cnt;
                if (cnt > m)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto v : nums) {
            left = max(left, (long long)v);
            right += v;
        }
        while (left <= right) {
            long long mid = (left + right)/2;
            if (checkSplit(nums, m, mid)) 
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
/*
/*binary search
Obviously, the final result is in the interval [left, right] (where left is the maximal number in the array, right is sum of all numbers).
So, what we need to do is to find out the first element in [left, right], which exactly we cannot split the array into m subarrays whose sum is no greater than that element. Then its previous one is the final result. 
The progress is much similar to lower_bound in C++.
如果m和数组nums的个数相等，那么每个数组都是一个子数组，所以返回nums中最大的数字即可，如果m为1，那么整个nums数组就是一个子数组，返回nums所有数字之和，所以对于其他有效的m值，返回的值必定在上面两个值之间，所以我们可以用二分搜索法来做
*/
