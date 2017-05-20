class Solution {
public:
//binary search to find sqrt(x)
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num/i; ++i) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};

//2147483647 TLE
