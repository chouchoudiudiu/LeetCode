class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int v[n + 1] = {0};
        v[0] = 0, v[1] = 1, v[2] = 2;
        for (int i = 3; i <= n; ++i)
            v[i] = v[i - 1] + v[i - 2];
        return v[n];
    }
};

//////////////////////////////////////////////////////////////
class Solution { (slower?)
public:
//fib
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};
