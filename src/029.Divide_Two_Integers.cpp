class Solution {
public:
    int divide(int dividend, int divisor) { // beichushu , chushu
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dend = llabs(dividend);
        long long dsor = llabs(divisor);
        int shift = 0, res = 0;
        while(dsor << shift <= dend ) {
            ++shift;
        } //final answer would be smaller than 2^shift
        while(--shift >= 0) {
           if(dsor << shift <= dend ) {
               dend -= (dsor << shift);
               res |= 1 <<shift;
           }    
        }
        return sign == 1 ? res : -res;
    }
};
