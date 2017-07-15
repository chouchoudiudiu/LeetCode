class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqCap; //min heap for capital and profit
        priority_queue<int> pqProfit; //maxheap for profit
        for(size_t i = 0; i < Capital.size(); ++i)
            pqCap.push({Capital[i], Profits[i]});
        for(size_t i = 0; i < k; ++i) {
            while(!pqCap.empty() && pqCap.top().first <= W) {//足够启动的都放进去，找出profit最大的
                pqProfit.push(pqCap.top().second);
                pqCap.pop();
            }
            if(pqProfit.empty())
                break; //没有足够的资金启动新的项目！
            W += pqProfit.top();//选出可能开始的项目中profit最高的, 动态更新W
            pqProfit.pop();
        }
        return W; //W is dynamically changed
    }
};

//greedy! each time we find a project with max profit and within current capital capability.
/*
把资本利润对放在最小堆中，这样需要资本小的交易就在队首，然后从队首按顺序取出资本小的交易，如果所需资本不大于当前所拥有的资本，那么就把利润资本存入最大堆中，注意这里资本和利润要翻个，因为我们希望把利润最大的交易放在队首，便于取出
*/
