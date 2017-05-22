class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);
        int cnt = 0;
        if (A[1] - A[0] == A[2] - A[1])
            ++cnt;
        dp[2] = cnt;
        for (int i = 3; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
            cnt += dp[i];
        }
        
        return cnt;
    }
};

/*
[1,2,3,4] 以3结尾的时候dp[2] = 1, 当发现234也可以, dp[3] = dp[2] + 1,一方面dp[2]之前的123延续到1234，另一方面增加了234这个新串，而之前
的dp[2]的解123依然存在，count继续添加新的即可；如果dp[2] 之前是0，就只添加234
*/
