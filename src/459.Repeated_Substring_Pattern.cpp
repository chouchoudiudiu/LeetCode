class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= n/2; ++i) {
            if(n%i == 0) {
                string p = s.substr(0, i), tmp;
                for(int t = 0; t < n/i; ++t)
                    tmp += p;
                if(s == tmp)
                    return true;
            }
        }
        return false;
    }
};
