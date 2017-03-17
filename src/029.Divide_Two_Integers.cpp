class Solution {
public:
    int divide(int dividend, int divisor) {// beichushu , chushu
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long dend = abs((long long)dividend), dsor = abs((long long)divisor);
        int shift = 0, res = 0;
        while (dsor << shift <= dend ) {
            ++shift;
        }
        while (--shift >= 0) {
            if (dsor << shift <= dend) {
                dend -= dsor << shift;
                res |= 1 << shift;
            }
        }
        if ((dividend < 0) ^ (divisor < 0))   
            res = -res;
        return res >= INT_MAX ? INT_MAX: res;
    }
};
