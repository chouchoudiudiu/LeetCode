class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;
        int k = costs[0].size();
        vector<int> d = costs[0]; //initialization
        for (int i = 1; i < costs.size(); ++i) {
            vector<int> temp(k, INT_MAX);
            for (int j = 0; j < k; ++j) {
                for (int c = 0; c < k; ++c) {
                    if (c != j)
                        temp[j] = min(temp[j], d[c]);//当前房子选择j，前一个房子选择其他各种颜色后的最小cost,每个颜色j都试过去
                }
                temp[j] += costs[i][j];
            }
            d = temp;
        }
        return *min_element(d.begin(), d.end());
    }
};

//前一个房子paint成除了j以外各种颜色的总的最小代价temp[j] = min(temp[j], d[c]); 
