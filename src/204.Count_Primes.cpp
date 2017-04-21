class Solution {
public: //Sieve of Eratosthenes
    int countPrimes(int n) { //primes less than n
        vector<bool> primes(n, true);
        for (int i = 2; i <= sqrt(n); ++i) { //sqrt is enough
            if (primes[i]) {
                for (int j = i*i; j < n; j += i)
                    primes[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; ++i)
            cnt += primes[i] ? 1 : 0;
        return cnt;
    }
};
