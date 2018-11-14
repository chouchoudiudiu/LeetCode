class Solution {
public:
//题意：给定一个元素互不相同且均为正数的数组，让你用该数组中的数组合成target（可以重复使用），问有多少种。
//need to use dp when only count needed!
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;//choose none
        //sort(nums.begin(), nums.end()); //not necessary at all
        for (int i = 1; i <= target; ++i)
            for (auto v : nums) {
                if (v <= i) //i, not target
                    dp[i] += dp[i - v]; //所有成功构成i-v的组合比如[a,b,c],[d,e]都加上v这个数字，他们的和[a,b,c,v]，[d,e,v]就成了i
            }
        return dp[target];
    }
};

//有负数的情况可能存在无限符合要求的解。(比如你想想有个-1的，我正数随便加，然后再减回去)
//所以必须要有限制条件，限制条件有很多啊 比如要求解的长度为L，或者不超过L，或者每个数只能使用X次等等
