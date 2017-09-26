class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1;
    }
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '2';
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k = 0; k < 4; ++k) {
                int x = r + dir[k][0];
                int y = c + dir[k][1];
                if(isValid(x, y, m, n) && grid[x][y] == '1') {
                    q.push({x, y});
                    grid[x][y] = '2';
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
//这种写法改写了grid的值，但是对于这种多次bfs的情况应该怎么设置visited?
