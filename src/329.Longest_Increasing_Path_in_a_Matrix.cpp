class Solution {
public:
    bool isValid (vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& path, int i, int j) {
        if (path[i][j] != 0)
            return path[i][j];//memorization
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int maxLen = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if (isValid(matrix, x, y) && matrix[x][y] > matrix[i][j])
                maxLen = max(maxLen, helper(matrix, path, x, y) + 1);
        }
        path[i][j] = maxLen;
        return maxLen;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 1;
        vector<vector<int>> path(m, vector<int>(n, 0));//max len starting from i,j
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                maxLen = max(maxLen, helper(matrix, path, i, j));
            }
        return maxLen;
    }
};
