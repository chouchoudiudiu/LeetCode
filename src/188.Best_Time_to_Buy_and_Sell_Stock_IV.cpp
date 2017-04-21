class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k <= 0)
            return 0;
        int maxProfit = 0, len = prices.size();
        if (k > len/2) {//一次交易包括一次买和一次卖，两天
            for (int i = 1; i < len; ++i) {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }
        int global[k + 1] = {0};
        int local[k + 1] = {0};
        for (int i = 1; i < len; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; --j) {
                local[j] = max(global[j - 1] + max(0, diff), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
};
//只看j
//local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
//global[i][j] = max(local[i][j], global[i - 1][j])，
