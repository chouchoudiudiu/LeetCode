class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0, distinct = 0;
        int cnt[256] = {0};
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (cnt[s[i]] == 0)
                ++distinct;
            cnt[s[i]]++;
            while (distinct > k) {
                --cnt[s[j]];
                if (cnt[s[j++]] == 0)
                    --distinct;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};
