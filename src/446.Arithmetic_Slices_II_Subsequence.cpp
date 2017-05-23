class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size(); 
        vector<unordered_map<int, int>> m(n);// 差与长度
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)A[i] - (long long)A[j];
                if (diff > INT_MAX || diff < INT_MIN)
                    continue;
                int d = (int)diff;
                if (!m[i].count(d))
                    m[i][d] = 0;
                ++m[i][d]; //首先自增1，表示长度为1；每个j不同所以d也不同, m[i][d]应该永远是1？
                if (m[j].count(d)) {
                    m[i][d] += m[j][d]; //先有468,再有之前的1个结果加上2468
                    res += m[j][d];
                }
            }
        return res;
    }
};

/*
1：[2,4,6]

2：[4,6,8] [2,4,6,8]

1：[2,6,10]

3：[6,8,10] [4,6,8,10] [2,4,6,8,10]

 [0,2000000000,-294967296]
*/
