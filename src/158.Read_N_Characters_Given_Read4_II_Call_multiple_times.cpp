// Forward declaration of the read4 API.
int read4(char *buf);
//void* memcpy( void* dest, const void* src, std::size_t count );
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        //read from local store buf first
        int fromStore = min(nRead - nWrite, n);
        memcpy(buf, buf4 + nWrite, sizeof(fromStore));
        nWrite += fromStore;
        int cnt = fromStore;
        
        while(cnt < n) {
            nRead = read4(buf4);
            nWrite = min(nRead, n - cnt);
            memcpy(buf + cnt, buf4, sizeof(nWrite)); //buf + cnt 
            cnt += nWrite;
            if(nRead < 4)
                break;
        }
        return cnt;
    }
    
    char buf4[4];
    int nWrite = 0, nRead = 0;
};

/*
"ab"
[1,2]
Output:
["a","a"]
Expected:
["a","b"]
*/
