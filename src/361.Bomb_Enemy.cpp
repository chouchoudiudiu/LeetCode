class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> l2r(m, vector<int>(n, 0)), r2l = l2r, t2b = l2r, b2t = l2r;//l2r,r2l,t2b,b2t
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = (j == 0 || grid[i][j] == 'W') ? 0 : l2r[i][j - 1];
                l2r[i][j] = grid[i][j] == 'E' ? t + 1 : t; 
            }
            for (int j = n - 1; j >= 0; --j) {
                int t = (j == n - 1 || grid[i][j] == 'W') ? 0 : r2l[i][j + 1];
                r2l[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for (int j = 0; j < n; ++j){
            for (int i = 0; i < m; ++i) {
                int t = (i == 0 || grid[i][j] == 'W') ? 0 : t2b[i - 1][j];
                t2b[i][j] = grid[i][j] == 'E' ? t + 1 : t; 
            }
            for (int i = m - 1; i >= 0; --i) {
                int t = (i == m - 1 || grid[i][j] == 'W') ? 0 : b2t[i + 1][j];
                b2t[i][j] = grid[i][j] == 'E' ? t + 1 : t; 
            }
        }
        int maxKilled = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0')//can only be place in empty space
                    maxKilled = max(maxKilled, l2r[i][j] + r2l[i][j] + t2b[i][j] + b2t[i][j]);
            }
        
        return maxKilled;
    }
};
