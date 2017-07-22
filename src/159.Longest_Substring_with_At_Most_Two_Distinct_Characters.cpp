class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count[256] = {0};
        int maxLen = 0, distinct = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (count[s[i]] == 0)
                ++distinct;
            count[s[i]]++;
            while (distinct > 2) {
                count[s[j]]--;//shifting right
                if (count[s[j++]] == 0)
                    --distinct;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};


or
           while(distinct > 2) {
                if(--cnt[s[j++]] == 0)
                    --distinct;
            }
