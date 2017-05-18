class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false}, cols[9][9] = {false}, blocks[9][9] = {false};
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3; //find corresponding block
                    if (rows[i][val] || cols[j][val] || blocks[k][val])
                        return false;
                    rows[i][val] = cols[j][val] = blocks[k][val] = true;
                }
            }
        return true;
    }
};
