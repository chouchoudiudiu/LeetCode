class Solution {
public:   
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) 
                    q.push({i, j});
                else
                    matrix[i][j] = INT_MAX;
            }
        }
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int i = 0; i < 4; ++i) {
                int x = r + dirs[i][0];
                int y = c + dirs[i][1];
                if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[r][c]) {//INT_MAX
                    q.push({x, y});
                    matrix[x][y] = matrix[r][c] + 1;
                }
            }
        }
        return matrix;
    }
};
//第一步，把所有0出发1步可达的1都放进去，继续往高处走，把通过这些0一步可以到达的1再接着找INT_MAX说明是还未更新过
//almost identical to walls and gates
