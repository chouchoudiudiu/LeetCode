class Solution {
public:
//BFS shortest path
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty())
            return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q; //coord
        vector<vector<bool>> visited(m, vector<bool>(n, false));//not necessary matrix, just test for fun
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) //从0出发
                    q.push(make_pair(i, j));
            }
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = true;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int r = x + dir[i][0];
                int c = y + dir[i][1];
                if (r >= 0 && r < m && c >= 0 && c < n && rooms[r][c] > 0  && !visited[r][c]) {//going outwards, no turn/revisit
                    rooms[r][c] = rooms[x][y] + 1;
                    visited[r][c] = true; //if use visited, update here
                    q.push(make_pair(r, c)); //becomes reachable
                }
            }
        }
    }
};

class Solution {
public:
//BFS
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty())
            return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(rooms[i][j] == 0)
                    q.push({i, j});
            }
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int i = 0; i < 4; ++i) {
                int x = r + dir[i][0];
                int y = c + dir[i][1];
                if(x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] > rooms[r][c]) {
                    q.push({x, y});
                    rooms[x][y] = rooms[r][c] + 1;
                }
            }
        }
    }
};
