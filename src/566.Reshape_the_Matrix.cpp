class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.empty())
            return nums;
        int m = nums.size(), n = nums[0].size();
        if(m*n != r*c)
            return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j) {
                int idx = i*c + j;
                res[i][j] = nums[idx/n][idx%n];
            }
        return res;
    }
};
