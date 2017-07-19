class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || start.empty() || destination.empty())
            return false;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.first == destination[0] && p.second == destination[1])
                return true;
            for(auto d : dirs) {
                int x = p.first;
                int y = p.second;
                while(x + d[0] >= 0 && x + d[0] < m && y + d[1] >= 0 && y + d[1] < n && maze[x + d[0]][y + d[1]] == 0) {
                    x += d[0];
                    y += d[1];//keep rolling
                }
                if(!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return false;
    }
};

//只要我们有了方向，只要一直在那个方向上往前走，每次判读是否越界了或者是否遇到墙了即可
class Solution {
public:
    vector<vector<int>> dirs{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty())
            return true;
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        //visited[start[0]][start[1]] = true;
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            maze[t.first][t.second] = 2;
            if (t.first == destination[0] && t.second == destination[1])
                return true;
            for(auto d : dirs) {
                int x = t.first;
                int y = t.second;
                while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                    x += d[0];
                    y += d[1];
                }
                x -= d[0];
                y -= d[1];
                if(maze[x][y] == 0) {
                    q.push({x, y});
                    //visited[x][y] = true;
                }
            }
        }
        return false;
    }
};

//只要我们有了方向，只要一直在那个方向上往前走，每次判读是否越界了或者是否遇到墙了即可
