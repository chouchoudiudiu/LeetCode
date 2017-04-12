class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n)
            return isOneEditDistance(t, s);
        if (m - n > 1)
            return false;
        int i = 0;
        while (i < n) {
            if (s[i] == t[i])
                ++i;
            else {
                if (m > n && s.substr(i + 1) == t.substr(i))
                    return true;
                if (m == n && s.substr(i + 1) == t.substr(i + 1))
                    return true;
                return false;//all other cases
            }
        }
        return m == n ? false:true;
    }
};
/*
"helo"
"hel"
*/
