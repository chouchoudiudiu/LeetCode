class Solution {
public:
    int findNthDigit(int n) {
        long num = 0, lastnum = 0;
        int k = 0;
        while (num < n) {
            lastnum = num;
            num += 9 * (k + 1) *pow(10, k);
            ++k; //k位数之前一共已经有lastnum个digit, 这个数定位在k位数
        }
        int dist = n - lastnum; //差距 要200，之前lastnum是189，差距是11
        if (dist % k == 0) {
            int targetNum = pow(10, k - 1) + dist/k - 1;
            return targetNum%10;
        }
        else {
            int targetNum = pow(10, k - 1) + dist/k; //start from 100
            dist -= dist/k*k; //要第几位
            return (int)(targetNum/pow(10, k - dist))%10; //(int)
        }
    }
};
/*
calculate how many digits the number has.
calculate what the number is.
find out which digit in the number is we wanted.
*/
