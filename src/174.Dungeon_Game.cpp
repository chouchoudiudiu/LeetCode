class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty())
            return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]); //最后还要有1
        for (int i = m - 2; i >= 0; --i)
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        for (int j = n - 2; j >= 0; --j)
            dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        return dp[0][0];
    }
};

//DP[i][j]:  各个位置的最优的起始生命值。每个点的起始与结束生命值都至少为1，才能来到这里或者到下一个房间
//必须从右往左，从下往上，根据后面的状态判断前面
