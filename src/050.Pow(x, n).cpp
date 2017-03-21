class Solution {
public:
    
    double myPow(double x, long n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x; //
        bool neg = false;
        if (n < 0)
        {
            neg = true;
            n = -n; //potentialoverflow
        }
        
        double res = myPow(x, n/2); //算一遍即可。。。
        res = res*res;
        res = n%2 ? x*res : res;
        return neg ? 1/res : res;
    }
    
    double myPow(double x, int n) {
        if (x == 0.0)
            return 0.0;
        long ln = (long)n;
        return myPow(x, ln);
    }
};

/*
0.00001
2147483647
maximum value of int: 2147483647
minimum value of int: -2147483648
*/
