class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        visited[i][j] = true;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0,-1}};
        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1 && !visited[x][y] && matrix[x][y] >= matrix[i][j]) 
                dfs (matrix, visited, x, y);
        }
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<pair<int, int>> res;
        //from outer to inner
        for (int i = 0; i < n; ++i) {
            dfs(matrix, pacific, 0, i);
            dfs(matrix, atlantic, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n - 1);
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        return res;
        
    }
};
