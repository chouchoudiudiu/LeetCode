class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int k) {
        if (k == word.size()) 
            return true;
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < 4; ++i) {
            int x = row + dir[i][0];
            int y = col + dir[i][1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                char c = board[x][y];
                if (c == word[k])
                {
                    board[x][y] = '.';
                    if (helper(board, word, x, y, k + 1))
                        return true;
                    board[x][y] = c;
                }
            }
        }
        //  The same letter cell may not be used more than once. 不走回头路
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())  return false;
        int m = board.size(), n = board[0].size();
        if (m == 1 && n == 1 && word.length() == 1)
            return board[0][0] == word[0];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (helper(board, word, i, j, 0)) //不在这里判断word[0], 防止走回头路，因为这里没有标记
                    return true;
            }
        return false;
    }
};
