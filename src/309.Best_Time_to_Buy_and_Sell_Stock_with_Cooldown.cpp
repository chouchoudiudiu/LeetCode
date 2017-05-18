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
