class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long sum = 0;
        for (auto v : nums)
            sum += v;
        if (sum % 2 != 0) return false;
        int target = sum/2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto v : nums) {
            for (int i = target; i >= v; --i) {//反之会如何？
                dp[i] = dp[i] || dp[i - v]; //5,2,3,6 target=8; 第一个v=5, 8 7 6 5 是5往上可能或希望取到的值，取决于有没有数可以和它加到678 
                if(dp[target])
                    return true;
            }
         }
        return dp[target];
    }
};

//[7,5,13,5]for (int i = v; i <= target; ++i) //会如何？会导致 v = 7, dp[7] = true, dp[14] = true
//v = 5时候 5,7,10(因为10-5 = 5即自己已经存在，但是其实需要2个不同的5),12,14,15都是1了。。。
//for (int i = target; i >= v; --i) { 则到第一个5时候，只有12,7,5是1
