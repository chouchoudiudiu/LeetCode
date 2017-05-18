class Solution {
public:
//median in two direction
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> x, y;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        //odd, how about even?
        int midX = x[x.size()/2], midY = y[y.size()/2];
        int minDist = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    minDist += abs(i - midX) + abs(j - midY);
                }
            }
        return minDist;
    }
};//need to check proof
