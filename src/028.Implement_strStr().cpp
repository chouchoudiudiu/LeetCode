class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if (n == 0)   return 0;
        for ( int i = 0; i <= m - n; ++i) {
            int p1 = i, p2 = 0;
            while (p1 < m && p2 < n && haystack[p1] == needle[p2]) {
                ++p1;
                ++p2;
            }
            if (p2 == n)
                return i;
        }
        
        return -1;
    }
};
