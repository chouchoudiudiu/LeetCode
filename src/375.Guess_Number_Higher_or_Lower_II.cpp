class Solution {
public:
/* O(n^3)
那么我们需要建立一个二维的dp数组，其中dp[i][j]表示从数字i到j之间猜中任意一个数字最少需要花费的钱数，那么我们需要遍历每一段区间[j, i]，维护一个全局最小值global_min变量，然后遍历该区间中的每一个数字，计算局部最大值local_max = k + max(dp[j][k - 1], dp[k + 1][i])，这个正好是将该区间在每一个位置都分为两段，然后取当前位置的花费加上左右两段中较大的花费之和为局部最大值，然后更新全局最小值，
由于我们需要 “保证得到结果”，也就是说对于指定 k 的选择，我们需要准备最坏情况 cost 是以下三种结果生成的 subproblem 中cost 最大的那个； 然而同时对于一个指定区间 [i , j] ，我们可以选择任意 i <= k <= j ，对于这个 k 的主观选择可以由我们自行决定，我们要选的是 k  s.t. 其子问题的 cost + 当前操作 cost 最小的一个，至此，每次决策就构成了一次 MiniMax 的博弈。

同时因为我们有很多的 overlapping subproblems ，而且问题本身具有 optimal substructure，提高算法效率最简单直观的方式，就是用 int[][] dp 做缓存，来进行自顶向下的记忆化搜索 ( top-down memoized search).
*/
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));//range 1-n; (dp[0][n - 1])
        return getCost(dp, 1, n); // L R
    }
    
    int getCost(vector<vector<int>>& dp, int l, int r) {
        if(l >= r)
            return 0;
        if(dp[l][r] != 0)
            return dp[l][r];
        int res = INT_MAX;
        for (int k = l; k <= r; ++k) {
            res = min(res, k + max(getCost(dp, l, k - 1), getCost(dp, k + 1, r)));
        }
        
        dp[l][r] = res;
        return res;
    }
};

/*f[L][R]表表示猜[L, R]这个区间里面的数字需要多少花费，如果我猜是k, L<=k<=R
考虑比较坏的情况，我猜错了，那么花费就是
max(f[L][k-1], f[k+1][R]) + k
为啥呢，因为你猜错了，然后会告诉你是大了还是小了，大了在[L, k-1]这个区间，小了在[k+1, R]这个区间，考虑最坏情况，选大的。
所以状态转移是

f[L][R] = min{max(f[L][k-1], f[k+1][R]) + k}, L<=k<=R
简单的说就是枚举k，看花费是多少，选一个最小的。
*/
