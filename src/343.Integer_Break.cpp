class Solution {
public:
//use as many 3s as possible, break into 2s and 3s
    int integerBreak(int n) {
        if (n == 2 || n == 3)
            return n - 1;
        int res = 1;
        while (n > 4) {//4 应该拆成4或者2*2，比3*1大
            res *= 3;
            n -= 3;
        }
        return res*n; //最后剩余2或者4
    }
};
