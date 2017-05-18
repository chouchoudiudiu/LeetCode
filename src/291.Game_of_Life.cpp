class Solution {
public:
    int checkLiveNeighbors(vector<vector<int>>& board, int r, int c, int m, int n) {
        int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] & 1))//表示当前状态是1
                ++cnt;
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int cnt = checkLiveNeighbors(board, i, j, m, n);
                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = 1; //1->0 01
                    if (cnt == 2 || cnt == 3)
                        board[i][j] = 3; //1->1 11
                }
                else {
                    if (cnt == 3)
                        board[i][j] = 2; //0->1: 死->活 10
                }
            }
        //update board
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
    }
};
/*
[[1]]
状态: 前一位表示下一代的状态, 后一位表示当前的状态, 最后shift right
00: 死->死
10: 死->活
01: 活->死
11: 活->活
*/
