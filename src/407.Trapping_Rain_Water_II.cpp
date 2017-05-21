class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        auto comp = [&heightMap](const pair<int, int>& a, const pair<int, int>& b) {
            return heightMap[a.first][a.second] > heightMap[b.first][b.second]; //a min heap
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0, level = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({i, j});
                    visited[i][j] = true;
                }
            }
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            level = max(level, heightMap[v.first][v.second]); //level是慢慢升高的，有多少先算多少，而v也是被从小到大访问到的
            for (int i = 0; i < 4; ++i) {
                int x = v.first + dir[i][0];
                int y = v.second + dir[i][1];
                if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1 && !visited[x][y]) {
                    visited[x][y] = true;
                    pq.push({x, y});
                    if (level > heightMap[x][y]) 
                        res += level - heightMap[x][y]; //周围如果有小于level的，已经访问过
                }
            }//matrix的能够灌水的高度，取决于最外围一圈的高度中的最小值，v
        }//从最低点开始进行BFS，最低点周围填充高度肯定等于最低点。
        return res;
    }
};
