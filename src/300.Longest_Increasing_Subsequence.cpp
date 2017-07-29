class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};

//Follow up: Could you improve it to O(n log n) time complexity? 
//binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        for(auto v : nums) {
            auto pos = lower_bound(vec.begin(), vec.end(), v);
            if(pos == vec.end()) //v is larger than any of those
                vec.push_back(v);
            else
                *pos = v;
        }
        return vec.size();
    }
};

//binary search的解法。。。。
//只是size相同  2 3 5 7
/*
lower_bound返回数组中第一个不小于指定值的元素，跟上面的算法类似，我们还需要一个一维数组v，然后对于遍历到的nums中每一个元素，找其lower_bound，如果没有lower_bound，说明新元素比一维数组的尾元素还要大，直接添加到数组v中，跟解法二的思路相同了。如果有lower_bound，说明新元素不是最大的，将其lower_bound替换为新元素，这个过程跟算法二的二分查找法的部分实现相同功能，最后也是返回数组v的长度，注意数组v也不一定是真实的LIS
这个我不认同。。。得到的是 2 3 7 18
*/
