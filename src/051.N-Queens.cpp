class Solution {
public:
//any conflict with previous rows
    bool isValid(vector<int>& columns, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (columns[i] == col) //check column
                return false;
            int rowDist = row - i;
            int colDist = abs(columns[i] - col);
            if (rowDist == colDist)
                return false;
        }
        return true;
    }
    
    void nQueens(int row, vector<int>& columns, vector<vector<int>>& res, int n) {
        if (row == n) {
            res.push_back(columns);
            return;
        }   
        for (int i = 0; i < n; ++i) {
            if (isValid(columns, row, i)) {
                columns[row] = i;
                nQueens(row + 1, columns, res, n);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> queens;
        vector<vector<int>> res;
        vector<int> columns(n);
        nQueens(0, columns, res, n);
        
        for (auto v:res) {
            vector<string> oneSolution;   
            for (int row = 0; row < n; ++row) {
                string s(n, '.');
                s[v[row]] = 'Q';
                oneSolution.push_back(s);
            }
            queens.push_back(oneSolution);
        }
        return queens;
    }
};
