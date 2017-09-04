class Solution {
public:
    int helper(long n) { //can't use int, 2147483647
        if(n == 1)
            return 0;
        if(n%2 == 0)
            return helper(n/2) + 1;
        else
            return min(helper(n - 1), helper(n + 1)) + 1;
    }
    int integerReplacement(int n) {
        return helper(n); //long(n) is also fine
    }
};
