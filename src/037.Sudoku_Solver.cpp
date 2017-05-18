class Solution {
public:
bool isValid(vector<vector<char> > &board, int x, int y)
    {
        bool rows[9] = {false}, cols[9] = {false}, blocks[9] = {false};
        for (int i = 0; i < 9; ++i) {
            if (board[x][i] != '.') {
                int val = board[x][i] - '1';
                if (rows[val])
                    return false;
                rows[val] = true;
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (board[i][y] != '.') {
                int val = board[i][y] - '1';
                if (cols[val])
                    return false;
                cols[val] = true;
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                if (board[x/3*3 + i][y/3*3 + j] != '.') {
                    int val = board[x/3*3 + i][y/3*3 + j] - '1';
                    if (blocks[val])
                        return false;
                    blocks[val] = true;
            }
        }
        return true;
    }

    
    bool solveSudokuWrapper(vector<vector<char>> &board, int curr) {
        if (curr == 81)
            return true;
        int x = curr/9, y = curr%9;
        if (board[x][y] != '.')
            return solveSudokuWrapper(board, curr + 1);
        else {
            for (int i = 1; i <= 9; ++i) {
                board[x][y] = i + '0';
                if (isValid(board, x, y)) {
                    if (solveSudokuWrapper(board, curr + 1)) //keep going
                        return true;
                }
                board[x][y] = '.'; //reset for every i
            }
            return false; //none works
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuWrapper(board, 0);
    }
};
/*
["51.748632","783652419","426139875","357986241","264317598","198524367","975863124","832491756","6412759.3"]*/
