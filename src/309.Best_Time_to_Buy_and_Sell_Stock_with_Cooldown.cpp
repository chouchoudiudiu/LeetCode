class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
	        return 0;

        int curSell = 0; //sell[i]
        int prevSell = 0;//sell[i - 2]
        int buy = -prices[0]; //buy[i]

        for (int i = 1; i < prices.size(); ++i) {
            int tmp = curSell; //sell[i - 1]
            curSell = max(curSell, buy + prices[i]);
            buy = max(buy, prevSell - prices[i]); //prevSell initialized as 0
            prevSell = tmp;
        }
        return curSell;
    }
};
//[1,2,3,0,2,4,5,2,4,7,11,2,4,7,9,10]
/*
令sell[i] 表示第i天未持股时，获得的最大利润，buy[i]表示第i天持有股票时，获得的最大利润。
sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);//今天无动作；第i - 1天持有股票时候已经有的最大利润 + 今天新的利润
buy[i] = max(buy[i - 1], (i >= 2 ? sell[i - 2] : 0) - prices[i]);//今天无动作；今天买股票，因为有cooldown, 追溯到前天
*/


///////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
	        return 0;

        int n = prices.size();
        vector<int> sell(n); //第i天未持股时，获得的最大利润
        vector<int> buy(n); //第i天持有股票时，获得的最大利润

        sell[0] = 0;
        buy[0] = -prices[0];

        for (int i = 1; i < n; ++i) {
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);//今天无动作；第i - 1天持有股票时候已经有的最大利润 + 今天新的利润
            buy[i] = max(buy[i - 1], (i >= 2 ? sell[i - 2] : 0) - prices[i]);//今天无动作；今天买股票，因为有cooldown, 追溯到前天
        }

        return sell[n - 1];
    }
};
//[1,2,3,0,2,4,5,2,4,7,11,2,4,7,9,10]
/*
//profit1[i] = max profit on day i if I sell
//profit2[i] = max profit on day i if I do nothing
1. profit1[i+1] means I must sell on day i+1, and there are 2 cases:
a. If I just sold on day i, then I have to buy again on day i and sell on day i+1 (can not buy on day i + 1), == sell on day i + 1
equivalent to you do nothing on day i, you delay your sell on day i to day i + 1
b. If I did nothing on day i, then I have to buy today and sell today (today means day i + 1)
Taking both cases into account, profit1[i+1] = max(profit1[i]+prices[i+1]-prices[i], profit2[i])
2. profit2[i+1] means I do nothing on day i+1, so it will be max(profit1[i], profit2[i])
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit1 = 0, profit2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int temp = profit1;
            profit1 = max(profit1 + prices[i] - prices[i - 1], profit2);
            profit2 = max(temp, profit2);
        }
        return max(profit1, profit2);
    }
};

/*
//profit1[i] = max profit on day i if I sell
//profit2[i] = max profit on day i if I do nothing
1. profit1[i+1] means I must sell on day i+1, and there are 2 cases:
a. If I just sold on day i, then I have to buy again on day i and sell on day i+1 (can not buy on day i + 1), == sell on day i + 1
equivalent to you do nothing on day i, you delay your sell on day i to day i + 1
b. If I did nothing on day i, then I have to buy today and sell today (today means day i + 1)
Taking both cases into account, profit1[i+1] = max(profit1[i]+prices[i+1]-prices[i], profit2[i])
2. profit2[i+1] means I do nothing on day i+1, so it will be max(profit1[i], profit2[i])
*/
