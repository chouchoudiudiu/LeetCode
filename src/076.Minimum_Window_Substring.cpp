class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        int minWindowLen = INT_MAX, minStart = -1, count = 0;
        int hasFound[256] = {0}, needToFind[256] = {0};
        for (auto c:t) { //t
            ++needToFind[c];
        }
        for (int begin = 0, end = 0; end < sLen; ++end) {
            if (needToFind[s[end]] == 0)
                continue;
            ++hasFound[s[end]];
            if (hasFound[s[end]] <= needToFind[s[end]])
                ++count;
            if (count == tLen) {
                while (hasFound[s[begin]] > needToFind[s[begin]] || needToFind[s[begin]] == 0) {
                    if (hasFound[s[begin]] > needToFind[s[begin]])
                        --hasFound[s[begin]];
                    ++begin;
                }
                int len = end - begin + 1; // +1
                if (len < minWindowLen) {
                    minWindowLen = len;
                    minStart = begin;
                }
            }
        }
        string res;
        if (minWindowLen < INT_MAX) {
            res = s.substr(minStart, minWindowLen);
        }
        return res;
    }
};
