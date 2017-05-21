class Solution {
public:
    int firstUniqChar(string s) {
        int m[256] = {0};
        for (auto c : s) 
            ++m[c];
        for (int i = 0; i < s.length(); ++i) {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
