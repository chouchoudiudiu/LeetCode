class Solution {
public:
//DFS
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) return true;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); //记录算过的值
        return helper(maze, dp, start[0], start[1], destination[0], destination[1]);
    }
    
     bool helper(vector<vector<int>>& maze, vector<vector<int>>& dp, int r, int c, int destr, int destc) {
        if (r == destr && c == destc)
            return true;
        if (dp[r][c] != -1) //already calculated
            return dp[r][c];
        int m = maze.size(), n = maze[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool res = false;
        maze[r][c] = -1; //in calculation, will reset later
        for (int i = 0; i < 4; ++i) {
            int dx = dirs[i][0];
            int dy = dirs[i][1];
            int x = r;
            int y = c;
            while(x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && maze[x + dx][y + dy] != 1) { 
                x += dx; ////not == 0, including -1 (pass it); to avoid duplication
                y += dy;
            }
            if (maze[x][y] == 0) {// a new position, otherwise might end up looping
                res = helper(maze, dp, x, y, destr, destc);
                if (res) 
                    return true;
            }
        } 
        
        maze[r][c] = 0; //originally 0, i.j must be an accessible pos (0)
        dp[r][c] = res;
        return res;
     }
};

//只要我们有了方向，只要一直在那个方向上往前走，每次判读是否越界了或者是否遇到墙了即可
