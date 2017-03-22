class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m*n);
        int layerMax = min(m, n)/2 + min(m, n)%2, k = 0;
        for (int layer = 0; layer < layerMax; ++layer) {
            if (layer == m - 1 - layer) {//one row left, or maybe just one single element
                for (int i = layer; i <= n - 1 - layer; ++i)
                    res[k++] = matrix[layer][i];
                break;
            }
            if (layer == n - 1 - layer) {//one col left
                for (int i = layer; i <= m - 1 - layer; ++i)
                    res[k++] = matrix[i][layer];
                break;
            }
            for (int j = layer; j < n - 1 - layer; ++j)
                res[k++] = matrix[layer][j];
            for (int i = layer; i < m - 1 - layer; ++i)
                res[k++] = matrix[i][n - 1 - layer];
            for (int j = n - 1 - layer; j > layer; --j)
                res[k++] = matrix[m - 1 - layer][j];
            for (int i = m - 1 - layer; i > layer; --i)
                res[k++] = matrix[i][layer];
        }
        
        return res;
    }
};
