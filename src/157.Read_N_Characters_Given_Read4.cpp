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
        int cnt = 0;
        while(cnt < n) {
            int read = read4(buf + cnt);
            cnt += min(read, n - cnt);
            if(read < 4)
                return cnt;
        }
        return n;
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

