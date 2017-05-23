class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int cnt = 0;
        while (n > 0) {
            n &= (n - 1);
            ++cnt;
        }
        return cnt;
    }
};
