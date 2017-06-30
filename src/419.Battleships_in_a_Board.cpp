class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty())
            return 0;
        int cnt = 0, m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) //只需要计算左或者上有没有。只计算第一个碰到的入口
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'X') {
                    if(i >= 1 && board[i - 1][j] == 'X')
                        continue;
                    if(j >= 1 && board[i][j - 1] == 'X')
                        continue;
                    ++cnt;
                }
            }
        return cnt;
    }
};
