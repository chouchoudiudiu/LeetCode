class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int res = 10, tmp = 9; 
        for (int i = 2; i <= min(n, 10); ++i) {
            tmp *= 10 - (i - 1);
            res += tmp;
        }
        return res;
    }
};
//第一位只能从1-9中选择，后面的几位由10-(i-1)确定
//the first i - 1 location takes up those numbers, 10 - (i - 1) numbers left
//通项公式为f(k) = 9 * 9 * 8 * ... (9 - k + 2)，那么我们就可以根据n的大小，把[1, n]区间位数通过通项公式算出来累加起来即可
