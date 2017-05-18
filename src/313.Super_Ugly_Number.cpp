class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0 || primes.empty())
            return 0;
        int k = primes.size();
        vector<int> uglyNumbers(n, 1);
        vector<int> p(k, 0); //下一个应该乘以的ugly number 的index
        vector<int> ugly(k);
        int i = 1;
        while (i < n) {
            int minIdx = 0;
            for (int j = 0; j < k; ++j) {
                ugly[j] = uglyNumbers[p[j]] * primes[j];
                if (ugly[j] < ugly[minIdx])
                    minIdx = j;
            }
            for (int j = 0; j < k; ++j) {
                if (ugly[j] == ugly[minIdx])
                    p[j]++;
            }
            uglyNumbers[i++] = ugly[minIdx];
        }
        
        return uglyNumbers[n - 1];
    }
};
