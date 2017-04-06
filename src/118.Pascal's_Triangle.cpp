class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        vector<int> row = {1};
        res.push_back(row);
        
        for (int i = 1; i < numRows; ++i) {
            row.clear();
            row.push_back(1);
            for (int j = 1; j < i; ++j)
                row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};

//////////////////////
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if (numRows == 0) return res;
        for (int i = 0; i < numRows; ++i) {
            res[i] = vector<int>(i + 1, 1);
            if (i >= 2) {
                for (int j = 1; j < i; ++j)
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};
