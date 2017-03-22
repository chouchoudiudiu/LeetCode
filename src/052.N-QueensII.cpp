class Solution {
public:
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
    
    void nQueens(int row, vector<int>& columns, int n, int& count) {
        if (row == n) {
            ++count;
            return;
        }   
        for (int i = 0; i < n; ++i) {
            if (isValid(columns, row, i)) {
                columns[row] = i;
                nQueens(row + 1, columns, n, count);
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<int> columns(n);
        int count = 0;
        nQueens(0, columns, n, count);
        return count;
    }
};
