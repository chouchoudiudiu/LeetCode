class Solution {
public:
    int findComplement(int num) {
        if (num == 0)   return 1;
        int cnt = 0, n = 0;
        while (num > 0) {
            if (!(num & 1)) { //a bit as 0
                n += pow(2, cnt);
            }
            num >>= 1;
            ++cnt;
        }
        return n;
    }
};
