class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while(n > len*cnt) {
            n -= len*cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1)/len;
        string s = to_string(start);
        return s[(n - 1)%len] - '0';
    }
};
/*
我们首先来分析自然数序列和其位数的关系，前九个数都是1位的，然后10到99总共90个数字都是两位的，100到999这900个数都是三位的，那么这就很有规律了，
我们可以定义个变量cnt，初始化为9，然后每次循环扩大10倍，再用一个变量len记录当前循环区间数字的位数，另外再需要一个变量start用来记录当前循环区间
的第一个数字，我们n每次循环都减去len*cnt (区间总位数)，当n落到某一个确定的区间里了，那么(n-1)/len就是目标数字在该区间里的坐标，加上start就是得到
了目标数字，然后我们将目标数字start转为字符串，(n-1)%len就是所要求的目标位，最后别忘了考虑int溢出问题，我们干脆把所有变量都申请为长整型的好了
*/


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
