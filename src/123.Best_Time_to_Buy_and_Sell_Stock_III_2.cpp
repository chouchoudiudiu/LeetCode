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
