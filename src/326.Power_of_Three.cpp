class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        while (n > 3) {
            if (n %3 != 0)
                return false;
            n /= 3;
        }
        return n%3 == 0;
    }
};

///////////////////////////////////////////
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n <= 0 ? false : (n == pow(3, round (log(n) / log(3)))); 
    }
};

//243->round
//If log10(n) / log10(3) returns an int, then n is a power of 3. (original post). But be careful here, you cannot use log (natural log) here, because it will generate round off error
//思路2：利用log函数，如果log3(n)为整数，那么说明n为3的幂。但是，利用log函数会出现四舍五入的问题，这是由精度造成的。我们可以采取特殊措施，判断n是否等于3的log3(n)次方，为了规避round off error，我们取pow(3,round(log3(n))),round函数对计算出来的log3(n)做了四舍五入。
