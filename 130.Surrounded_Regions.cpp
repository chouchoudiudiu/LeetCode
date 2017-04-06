class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) { //all the Os that can be reached from the border 'O'
        board[i][j] = '#';
        if (i - 1 > 0 && board[i - 1][j] == 'O') // be careful with > not >=, should not touch border seed Os
            dfs(board, i - 1, j, m, n);
        if (i + 1 < m - 1 && board[i + 1][j] == 'O')
            dfs(board, i + 1, j, m, n);
        if (j - 1 > 0 && board[i][j - 1] == 'O')
            dfs(board, i, j - 1, m, n);
        if (j + 1 < n - 1 && board[i][j + 1] == 'O')
            dfs(board, i, j + 1, m, n);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())  return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O') //start from edge
                    dfs(board, i, j, m, n);
            }
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};
/*
刚开始我的思路是DFS遍历中间的O，如果没有到达边缘，都变成X，如果到达了边缘，将之前变成X的再变回来。但是这样做非常的不方便，在网上看到大家普遍的做法是扫面矩阵的四条边，如果有O，则用DFS遍历，将所有连着的O都变成另一个字符，比如，这样剩下的O都是被包围的，然后将这些O变成X，把，这样剩下的O都是被包围的，然后将这些O变成X，把变回O就行了。
*/
