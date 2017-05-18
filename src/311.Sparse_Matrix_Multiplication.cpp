class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty())
            return {};
        int mA = A.size(), nA = A[0].size(), mB = B.size(), nB = B[0].size();
        vector<vector<int>> res (A.size(), vector<int>(nB, 0));
        vector<vector<int>> aNonZeros(mA), bNonZeros(nB);
        for (int i = 0; i < mA; ++i)
            for (int j = 0; j < nA; ++j) {
                if (A[i][j] != 0)
                    aNonZeros[i].push_back(j);//i行
            }
        for (int i = 0; i < mB; ++i)
            for (int j = 0; j < nB; ++j) {
                if (B[i][j] != 0)
                    bNonZeros[j].push_back(i); //j列
            }
        for(int i = 0; i < mA; i++)
            for(int j = 0; j < nB; j++) {
                int m = 0, n = 0;
                while (m < aNonZeros[i].size() && n < bNonZeros[j].size()) {
                    int idx_A = aNonZeros[i][m];
                    int idx_B = bNonZeros[j][n];
                    if (idx_A == idx_B) {
                        res[i][j] += A[i][idx_A]*B[idx_B][j];
                        ++m;
                        ++n;
                    }
                    else if (idx_A > idx_B)
                        ++n;
                    else
                        ++m;
                }
        }
        return res;
    }
};
