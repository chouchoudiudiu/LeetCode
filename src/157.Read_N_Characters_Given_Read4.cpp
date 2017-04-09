// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n/4; ++i) { //<= 可能除不尽
            int cnt = read4(buf + res);
            if (cnt == 0)
                break;
            res += cnt;
        }
        return min(res, n);
    }
};

/////////////////////////
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
//recursive
    int read(char *buf, int n) {
        int t = read4(buf);
        if (t >= n) return n;
        if (t < 4) return t;
        return read(buf + 4, n - 4) + 4; //&buf[4]
    }
};

