class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                colZero = true; 
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                rowZero = true; 
                break;
            }
        }
        
        for (int i = 1; i < m; ++i) 
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        
        if (rowZero) {
            for (int i = 0; i < n; ++i)
                matrix[0][i] = 0;
        }
        
        if (colZero) {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};

/*
- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0 (第一行对应值已经是0，不用管)
- 最后根据第一行第一列的flag来更新第一行第一列
*/
