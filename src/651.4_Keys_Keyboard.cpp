class Solution {
public:
    int maxA(int N) {
        int res = N;
        for (int i = 1; i <= N - 3; i++)
            res = max(res, maxA(i) * (N - i - 1));
        return res;
    }
};
/*
We use i steps to reach maxA(i) then use the remaining n - i steps to reach n - i - 1 copies of maxA(i)

For example:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
Here we have n = 7 and we used i = 3 steps to reach AAA
Then we use the remaining n - i = 4 steps: Ctrl A, Ctrl C, Ctrl V, Ctrl V, to reach n - i - 1 = 3 copies of AAA
*/
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        for(int i = 0; i <= N; ++i) {
            dp[i] = i;
            for(int j = 1; j <= i - 3; ++j)
                dp[i] = max(dp[i], dp[j]*(i - j - 1));
        }
        return dp[N];
    }
};
