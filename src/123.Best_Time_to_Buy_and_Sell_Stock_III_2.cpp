class Solution {
public:
//dp, local, global
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int local[3] = {0}; //for k = 2
        int global[3] = {0};
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 2; j >= 1; --j) {
                local[j] = max(global[j - 1] + max(0, diff), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }

        return global[2];
    }
};
//[1,2]
//http://www.cnblogs.com/grandyang/p/4281975.html 还讨论了覆盖

class Solution {
public:
//dp, local, global
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int local[n][3] = {0}; //for k = 2
        int global[n][3] = {0};
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                local[i][j] = max(global[i - 1][j - 1] + max(0, diff), local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }

        return global[n - 1][2];
    }
};

class Solution {
public:
//DP, like painters, find i as a bar, that we sell by ith day, and buy again by ith day
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int n = prices.size();
        int local[n][3] = {0}; //for k = 2
        int global[n][3] = {0};
        for(int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j <= 2; ++j) {
                local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff;
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[n - 1][2];
    }
};
在网友@loveahnee的提醒下，发现了其实上述的递推公式关于local[i][j]的可以稍稍化简一下，我们之前定义的local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，然后网友@fgvlty解释了一下第 i 天卖第 j 支股票的话，一定是下面的一种：

1. 今天刚买的
那么 Local(i, j) = Global(i-1, j-1)
相当于啥都没干

2. 昨天买的
那么 Local(i, j) = Global(i-1, j-1) + diff
等于Global(i-1, j-1) 中的交易，加上今天干的那一票

3. 更早之前买的
那么 Local(i, j) = Local(i-1, j) + diff
昨天别卖了，留到今天卖

但其实第一种情况是不需要考虑的，因为当天买当天卖不会增加利润，完全是重复操作，这种情况可以归纳在global[i-1][j-1]中，所以我们就不需要max(0, diff)了，那么由于两项都加上了diff，所以我们可以把diff抽到max的外面，所以更新后的递推公式为：

local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff

global[i][j] = max(local[i][j], global[i - 1][j])
/*
我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：

local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

global[i][j] = max(local[i][j], global[i - 1][j])

其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，而全局最优比较局部最优和前一天的全局最优。
*/
