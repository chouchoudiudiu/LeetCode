class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int ones = 0, connect = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    ++ones;
                    if(i > 0 && grid[i - 1][j] == 1) ++connect;
                    if(j > 0 && grid[i][j - 1] == 1) ++connect;
                }
            }
        return ones*4 - connect*2;
    }
};

/*
find how many 1 in the map. If without the consideration of surrounding cells, the total perimeter should be the total amount of 1 times 4.
find how many cell walls that connect with both lands. We need to deduct twice of those lines from total perimeter
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
//每个1有4个边，7*4，如果这个1有为1的邻居，每有一个减一
        if (grid.empty())
            return 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        int ones = 0, connect = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++ones;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if (x >= 0 && y >= 0 && x <= m - 1 && y <= n - 1 && grid[x][y] == 1)
                            ++connect;
                    }
                }
            }
        return ones*4 - connect;
    }
};


====================================================================================
    class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) { //this condition only!
                    perimeter += 4;
                    if(i >= 1 && grid[i - 1][j] == 1)
                        perimeter -= 2;
                    if(j >= 1 && grid[i][j - 1] == 1)
                        perimeter -= 2;
                }
            }
        return perimeter;
    }
};
