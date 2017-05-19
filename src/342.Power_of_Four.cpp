class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        int n = (int)sqrt(num);
        if (n * n != num)
            return false;
        return !(n & (n - 1));
    }
};
