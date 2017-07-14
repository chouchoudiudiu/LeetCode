class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || start.empty() || destination.empty())
            return 0;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1)); //shortest distance from start 
        dist[start[0]][start[1]] = 0;
        helper(dist, maze, start[0], start[1], destination[0], destination[1]);
        return dist[destination[0]][destination[1]];
    }
    
    void helper(vector<vector<int>>& dist, vector<vector<int>>& maze, int r, int c, int rowDest, int colDest) {
        if(r == rowDest && c == colDest)
            return;
        int m = maze.size(), n = maze[0].size();
        maze[r][c] = -1;
        for(size_t i = 0; i < 4; ++i) {
            int dx = dirs[i][0];
            int dy = dirs[i][1];
            int x = r;
            int y = c;
            int len = dist[r][c];
            while(x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && maze[x + dx][y + dy] != 1) {
                x += dx;
                y += dy;
                ++len;
            }
            if(dist[x][y] != -1 && len >= dist[x][y]) 
                continue;
            else{
                dist[x][y] = len;
                helper(dist, maze, x, y, rowDest, colDest);
            }
        }
        maze[r][c] = 0; //reset
    }
};
