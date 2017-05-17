class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) //-1
            return 0;
        int lastDigit = n%10;
        int sum = 0;
        int val1 = countDigitOne(n/10);
        int val2 = countDigitOne(n/10 - 1);
        sum = val1*(lastDigit + 1) + val2*(9 - lastDigit);
        sum += n/10 + (lastDigit >= 1);
        return sum;
    }
};
//比如456，先求45中带1的数字的个数t，这样无论最后一个数字取几都可以带1了，这不计算最后一位为1时候的右1,比如11只算了左边的1.最前面的t-1个可以是带0-9，最后一个可以是0-lastdigit
//仅最右边为1的情况（计算了之前没算的右边的1），不关心左边是什么，可以是0-44，即n/10
//需要注意10*，1000*之类的情况
//105为例，先算n/10可以保证2*6 （其中1和10后面可以带012345 就有了2*6个， 1x, 10x x = [0-5]），之后就是n/10-1（即不包括最后一个100）的含1数字
//以保证加上没加过的6-9，比如16-19
//=2*6+1*4+105/10+1 = 12 + 4 + 10 + 1 = 27
