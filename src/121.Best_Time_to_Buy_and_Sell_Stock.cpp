class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int maxProfit = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int low = prices[0], profit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > low)
                profit = max(profit, prices[i] - low);
            if(prices[i] < low)
                low = prices[i];
        }
        return profit;
    }
};
