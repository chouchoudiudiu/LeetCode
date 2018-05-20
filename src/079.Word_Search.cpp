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
///////

class Solution {
public:
    bool helper(vector<vector<char>>& board, int i, int j, int m, int n, string word, int idx) {
        if(idx == word.length())
            return true;
        char c = board[i][j];
        if(c != word[idx])
            return false;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int ii = 0; ii < 4; ++ii) {
            int new_i = i + dirs[ii][0];
            int new_j = j + dirs[ii][1];
            board[i][j] = '#';
            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                if(helper(board, new_i, new_j, m, n, word, idx + 1))
                    return true;
            }
            board[i][j] = c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        if(m == 1 && n == 1)
            return word.length() == 1 && board[0][0] == word[0];
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j) {
                if(word[0] == board[i][j]) {
                    if(helper(board, i, j, m, n, word, 0))
                        return true;
                }
            }
        return false;
    }
};
