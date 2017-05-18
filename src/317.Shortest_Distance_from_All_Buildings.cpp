class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = INT_MAX, target = 0;//initial 0 mark
        vector<vector<int>> sum(m, vector<int>(n , 0));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    vector<vector<int>> dist(m, vector<int>(n, 0));
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                         int r = q.front().first;
                         int c = q.front().second;
                         q.pop();
                         for (int k = 0; k < 4; ++k) {
                             int x = r + dirs[k][0];
                             int y = c + dirs[k][1];
                             if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == target) {
                                 --grid[x][y];//-- for next building
                                 dist[x][y] = dist[r][c] + 1;
                                 sum[x][y] += dist[x][y];// - 1; //started with 1
                                 q.push({x, y});
                                 res = min(res, sum[x][y]);
                             }
                         }
                    }
                    --target;//after finishing one building  
                }
            }
        return res == INT_MAX ? -1 : res; 
    }
};
//每层dist 和 sum 分开，而没有直接加到dist上， 应对的是有的1不能和任何0联通的情况? 都赋值为0可以吗
//https://segmentfault.com/a/1190000004187914 较常规的BFS做法
/*
对于每一个建筑的位置都进行一次全图的BFS遍历，每次都建立一个dist的距离场，由于我们BFS遍历需要标记应经访问过的位置，而我们并不想建立一个visit的二维矩阵，那么怎么办呢，这里用一个小trick，我们第一遍历的时候，都是找0的位置，遍历完后，我们将其赋为-1，这样下一轮遍历我们就找-1的位置，然后将其都赋为-2，以此类推直至遍历完所有的建筑物，然后在遍历的过程中更新dist和sum的值，并且更新结果res的值，最后根据res的值看是否要返回-1
*/
