class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), total = 0;
        vector<int> x, y;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        int xlen = x.size(), ylen = y.size();
        auto it_x = x.begin() + xlen/2, it_y = y.begin() + ylen/2;
        nth_element(x.begin(), it_x, x.end());
        nth_element(y.begin(), it_y, y.end());
        int xmedian = *it_x, ymedian = *it_y;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    total += abs(i - xmedian) + abs(j - ymedian);
                }
            }
        return total;
    }
};
//need to check proof
//median in two direction
/*
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        //odd, how about even?
        int midX = x[x.size()/2], midY = y[y.size()/2];
*/
