class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            while (!isalnum(s[l]) && l < r)
                ++l;
            while (!isalnum(s[r]) && l < r)
                --r;
            if (l > r)
                return false;
            if (tolower(s[l]) != tolower(s[r])) //tolower
                return false;

            ++l;
            --r;
        }
        return true;
    }
};

//"0P"
