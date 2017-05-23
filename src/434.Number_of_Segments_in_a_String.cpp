class Solution {
public:
    int countSegments(string s) {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ')
                continue;
            ++cnt;
            while (i < n && s[i] != ' ')
                ++i;
        }
        return cnt;
    }
};
