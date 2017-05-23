class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if(maze.empty() || ball.empty() || hole.empty())
            return "";
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // shortest distance from the ball
        vector<vector<string>> path(m, vector<string>(n, "impossible")); // best sequence according to shortest distance
        dfs(ball[0], ball[1], 0, "", maze, hole, dist, path);
        return path[hole[0]][hole[1]];
    }
    
    void dfs(int r, int c, int len, string s, vector<vector<int>>& maze, vector<int>& hole,
            vector<vector<int>>& dist, vector<vector<string>>& path) {
        if(len > dist[r][c] || (len == dist[r][c] && s >= path[r][c]) ) //lexicographically smallest way
            return;
        dist[r][c] = len; //guranteed smaller
        path[r][c] = s; //guranteed shorter
        int m = maze.size(), n = maze[0].size();
        int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        string dir = "lrud";
        for (int i = 0; i < 4; ++i) {
            int dx = dirs[i][0], dy = dirs[i][1];
            int x = r, y = c;
            while(x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && maze[x + dx][y + dy] == 0)
            {
                x += dx;
                y += dy;
                if(x == hole[0] && y == hole[1])
                    break;
            }
            dfs(x, y, len + abs(r - x) + abs(c - y), s + dir[i], maze, hole, dist, path); //new position, new length
        }
    }
};
