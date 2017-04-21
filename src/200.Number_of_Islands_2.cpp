class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1;
    }
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q; //stk okay ...
        q.push({i, j});
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            grid[x][y] = '0';
            for (int idx = 0; idx < 4; ++idx) {
                int newx = x + dir[idx][0];
                int newy = y + dir[idx][1];
                if (isValid(newx, newy, m, n) && grid[newx][newy] == '1') {
                    q.push({newx, newy});
                    grid[newx][newy] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, m, n);
                    ++cnt;
                }
            }
        return cnt;
    }
};
