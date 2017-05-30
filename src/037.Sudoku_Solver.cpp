class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y) {
        for(int row = 0; row < 9; ++row) {
            if(row != x && board[row][y] == board[x][y])
                return false;
        }
        for(int col = 0; col < 9; ++col) {
            if(col != y && board[x][col] == board[x][y])
                return false;
        }
        for(int row = x/3*3; row < x/3*3 + 3; ++row)
            for (int col = y/3*3; col < y/3*3 + 3; ++col) {
                if ((row != x || col != y) && board[row][col] == board[x][y])
                    return false;
            }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>>& board, int curr) {
        if (curr == 81)
            return true;
        int x = curr/9, y = curr%9;
        if (board[x][y] != '.')
            return solveSudokuHelper(board, curr + 1);
        for (int i = 1; i <= 9; ++i) {
            board[x][y] = i + '0';
            if (isValid(board, x, y) && solveSudokuHelper(board, curr + 1))
                return true;
            board[x][y] = '.'; 
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0);
    }
};
