class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN; //might be negative
        for(int l = 0; l < n; ++l) {
            vector<int> sums(m, 0);
            for(int r = l;  r < n; ++r) {
                for(int i = 0; i < m; ++i)
                    sums[i] += matrix[i][r];
                set<int> cumSet;
                cumSet.insert(0); //be careful
                int cumSum = 0, maxSumSubarray = INT_MIN;
                for(auto s : sums) {
                    cumSum += s;
                    auto it = cumSet.lower_bound(cumSum - k); //>=, binary search internally, 若找到=>中间一段<=k
                    if(it != cumSet.end())
                        maxSumSubarray = max(maxSumSubarray, cumSum - *it);//can be the same
                    cumSet.insert(cumSum);
                }
                res = max(res, maxSumSubarray);
            }
        }
        return res;
    }
};
//固定左边，移动右边，每一对[l, r], sum都先从上到下，依次从左到右加，得到的是每一行的sum
//Maximum Sum Rectangular Submatrix in Matrix dynamic programming/2D kadane
//What if the number of rows is much larger than the number of columns?
//space: O(row); time: O(col*col*row) or O(col*col*log(row)) ? 
