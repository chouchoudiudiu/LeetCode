class Solution {
public:
    string toHex(int num) {
        const string HEX = "0123456789abcdef";
        string s = "";
        unsigned int x = num;
        if (num < 0)
            x = num + UINT_MAX + 1; //two's complement, basically 1111 = 15 = -1; 1101 = 13 == -3 UINT_MAX == 2*INT_MAX+1
        while (x > 0) {
            s += HEX[x % 16];
            x /= 16;
        }
        reverse(s.begin(), s.end());
        return num == 0 ? "0" : s;
    }
};
//0
//IF USE INT_MAX, "7fffffff"
//2147483647 "7fffffff"
