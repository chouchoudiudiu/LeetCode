class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty())
            return 0;
        vector<int> d = costs[0];//initialization
        for (int i = 1; i < costs.size(); ++i) {
            vector<int> temp(3, INT_MAX);
            for (int j = 0; j < 3; ++j)  //当前选了0，就要看之前一个选1,2后的较小值；当前选了1，就看前一个选0,2后的较小值，类似
                temp[j] = costs[i][j] + min(d[(j + 1)%3], d[(j + 2)%3]);
            d = temp;
        }
        return min(d[0], min(d[1], d[2])); //the total cost of the last position picking 0 or 1 or 2 color
    }
};
