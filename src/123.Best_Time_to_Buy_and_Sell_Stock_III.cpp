class Solution {
public:
//DP, like painters, find i as a bar, that we sell by ith day, and buy again by ith day
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        vector<int> endsAt(n, 0);
        vector<int> startsAt(n, 0);
        int lowest = prices[0], highest = prices[n - 1];
        for (int i = 1; i < n; ++i) {//similar to buy I, max profit if first transaction ends at i
            endsAt[i] = max(endsAt[i - 1], prices[i] - lowest);
            lowest = min(prices[i], lowest);
        }
        for (int i = n - 2; i >= 0; --i) {//max profit if second transaction starts at i
            startsAt[i] = max(startsAt[i + 1], highest - prices[i]);
            highest = max(prices[i], highest);
        }
        int maxPro = 0;
        for (int i = 0; i < n; ++i)
            maxPro = max(maxPro, endsAt[i] + startsAt[i]);
        return maxPro;
    }
};
