class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[256] = {0};
        int maxLen = 0, maxCount = 0;//maxCount number of most frequent number
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt[s[i]]++;
            if (maxCount < cnt[s[i]])
                maxCount = cnt[s[i]];
            while (i - j + 1 - maxCount > k) { //+ 1; 如果删掉了maxCount的字母，是可能减去一个更大的数
                cnt[s[j++]]--;
            }
            maxLen = max(maxLen, i - j + 1);//satisfy the constraint
        }
        return maxLen;
    }
};

/*
如果没有k的限制，让我们求把字符串变成只有一个字符重复的字符串需要的最小置换次数，那么就是字符串的总长度减去出现次数最多的字符的个数。如果加上k的限制，我们其实就是求满足(子字符串的长度减去出现次数最多的字符个数)<=k的最大子字符串长度即可
Then as end increase, the whole substring from 0 to end will violate the rule, so we need to update start accordingly (slide the window). We move start to the right until the whole string satisfy the constraint again. Then each time we reach such situation, we update our max length.
"BABABCBAAAAAA"
2
*/
