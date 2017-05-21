class Solution {
public:
    int integerReplacement(int n) {
        long ln = n;
        return helper(ln);
    }
    int helper(long n) {
        if (n == 1)
            return 0;
        if (n % 2 == 0) //even
            return helper(n/2) + 1;
        else 
            return min(helper(n - 1) + 1, helper(n + 1) + 1);
    }
};
