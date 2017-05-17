class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> numSet;//ordered....long to avoid overflow..
        long long lt = t;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                numSet.erase(nums[i - k - 1]); //out of scope, retire, no threat
            auto pos = numSet.lower_bound(nums[i] - lt);  //include a number of same value as nums[i]; so x >= nums[i] - t (1)
            if (pos != numSet.end() && *pos - nums[i] <= lt) //so x <= nums[i] + t (2) (1)(2) ==> |x - nums[i]| <= t 
                return true;
            numSet.insert(nums[i]);
        }
        return false;
    }
};

//// 10 20 30 40 50 60 70 80 90
//Notice that lower_bound(30) returns an iterator to 30, whereas upper_bound(60) returns an iterator to 70.
//myset contains: 10 20 70 80 90
//nums[i] = 10, t = 2, we have [8, 9, 10, 11, 12] lower_bound 找到数大于等于8，只要看是否有超过12？即合法区间
/*
[2147483647,-2147483647]
1
2147483647
[-2147483648,-2147483647]
3
3
int: 32位

4-bit int

如果最高位是0，那么是正数，表示范围是0000 - 0111 (0 - 7)
如果最高位是1，那么是负数 (补码)，表示范围是
1000仍然是0
1111是先取反，取反变成0000，然后+1，然后是0001，然后变成负数，所以是-1。
那么
能表示的最小值应该是1000，先取反，取反之后是0111，然后+1，+1变成1000，然后变成负数，所以是-8。

在原码的表示中，1111应该是-7，原码表示的问题是用4个bit，本来可以表示出16个数，原码只能表示15个，因为0重复了 (0000 = 1000)
补码不存在这个问题，补码是能严格表示出[-(1 << (n - 1), 1 << (n - 1) - 1]，对应于刚才的4位来说是[-8, 7]


所以对于32位有符号int来说，是[-2147483648, 2147483647]

那么显然，int - int的时候，是可能出现overflow的，

32位unsigned int表示的范围是啥，很显然是从0到(1 << 32) - 1应该是4294967296 - 1 = 4294967295

2147483647 - (-2147483648) = 2 ^ 31 - 1 +　2 ^ 31 = 2 ^ 32 - 1
*/
