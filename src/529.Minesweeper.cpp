class Solution {
public:
    int dirs[8][2] = { { -1, -1 }, { -1, 1 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.empty() || click.empty())
            return {};
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        helper(board, click[0], click[1]);
        return board;
    }
    
    bool onBoard(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    
    void helper(vector<vector<char>>& board, int x, int y) {
        if(!onBoard(board, x, y))
            return;
        if(board[x][y] == 'E') {
            int mines = 0;
            for(size_t i = 0; i < 8; ++i) {//first check number of adj mines
                int dx = dirs[i][0];
                int dy = dirs[i][1];
                if(onBoard(board, x + dx, y + dy) && board[x + dx][y + dy] == 'M')
                    ++mines;
            }
            board[x][y] = mines > 0 ? (mines + '0') : 'B';
            if(mines == 0) { //no adjacent mines, if > 0 no need to explore more; no need to worry revisit since value changed
                for(size_t i = 0; i < 8; ++i) {
                    int dx = dirs[i][0];
                    int dy = dirs[i][1];
                    helper(board, x + dx, y + dy); //check neighbors
                }
            }
        }
    }
};
