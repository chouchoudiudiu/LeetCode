class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 0 || primes.empty())
            return 0;
        vector<int> uglyNumbers(n, 1);
        int sz = primes.size();
        vector<int> p(sz, 0); //下一个应该乘以的ugly number 的index
        int i = 1;
        while(i < n) {
            int minVal = INT_MAX;
            for(int j = 0; j < sz; ++j) 
                minVal = min(minVal, uglyNumbers[p[j]]*primes[j]);
             
            for(int j = 0; j < sz; ++j) {
                if(minVal == uglyNumbers[p[j]]*primes[j])
                    ++p[j];
            }
            uglyNumbers[i++] = minVal;
        }
        
        return uglyNumbers[n - 1];
    }
};
