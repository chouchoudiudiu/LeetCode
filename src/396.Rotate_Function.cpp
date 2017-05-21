class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty())
            return 0;
        int f = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            f += i*A[i]; //F[0]
            sum += A[i];
        }
        int maxF = f;
        for (int i = 1; i < n; ++i) {
            f += sum - n * A[n - i];
            maxF = max(maxF, f);
        }
        return maxF;
    }
};
//F(i) = F(i-1) + sum - n*A[n-i]
