class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return {};
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = rowIndex; j >= 1; --j) //reversely, otherwise increasing
                res[j] = res[j] + res[j - 1];
        }
        return res;
    }
};
