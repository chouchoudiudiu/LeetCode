class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1, 0);
        for (auto v : updates) {
            res[v[0]] += v[2];
            res[v[1] + 1] -= v[2];
        }
        //accumuated sum
        int sum = 0;
        for (int i = 0; i <= length; ++i) {
            sum += res[i];
            res[i] = sum;
        }
        res.pop_back();
        return res;
    }
};

//[ 0, 0, 0, 0, 0 ] [1, 4, 2]: [0 2 0 0 0 -2] => [0 2 2 2 2 0]
