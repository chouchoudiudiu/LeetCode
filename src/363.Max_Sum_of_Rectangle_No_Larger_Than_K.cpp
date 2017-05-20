class Solution {
public:
//What if the number of rows is much larger than the number of columns?
//space: O(row); time: O(col*col*row) or O(col*col*log(row)) ? 
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN; //might be negative
        for (int l = 0; l < n; ++l) {
            vector<int> sums(m, 0);
            for (int r = l; r < n; ++r) {
                for (int i = 0; i < m; ++i)
                    sums[i] += matrix[i][r];
                set<int> cumSet;
                cumSet.insert(0); //be careful!
                int cumSum = 0, maxSumSubArray = INT_MIN;
                for (auto s : sums) {
                    cumSum += s;
                    auto it = cumSet.lower_bound(cumSum - k);//>=, binary search internally, 若找到=>中间一段<=k
                    if (it != cumSet.end())
                        maxSumSubArray = max(maxSumSubArray, cumSum - *it);//can be the same
                    cumSet.insert(cumSum);
                }
                res = max(res, maxSumSubArray);
            }
        }
        return res;
    }
};

/*
[[5,-4,-3,4],[-3,-4,4,5],[5,1,5,-4]]
3
*/
