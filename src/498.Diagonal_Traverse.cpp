class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m*n);
        int r = 0, c = 0, k = 0; //k to control direction
        int dir[][2] = {{-1, 1}, {1, -1}}; //在右上(r - 1, c + 1)路上无法再右上，就向右；在左下路上无法再左下，就向下
        for (int i = 0; i < m*n; ++i) {
            res[i] = matrix[r][c];
            r += dir[k][0];
            c += dir[k][1];
            if (r == m) { r = m - 1; c += 2; k = 1 - k;} //c += 2
            if (c == n) { c = n - 1; r += 2; k = 1 - k;} // r += 2
            if (r < 0) { r = 0; k = 1 - k;}
            if (c < 0) { c = 0; k = 1 - k;}
        }
        return res;
    }
};

//if的顺序也要注意，不可以先《0
