class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxLen = 0;
        unordered_map<char, int> m;
        
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if(m.count(s[i]))
                j = max(j, m[s[i]] + 1); //出现过的字符的下一个字符; j记录最新的start //abba
            m[s[i]] = i;
            maxLen = max(maxLen, i - j + 1);
        }

        return maxLen;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxLen = 0;
        bool exists[256] = {false};
        
        while (i < s.length()) {
            if(!exists[s[i]])
                exists[s[i]] = true;
            else {
                maxLen = max(maxLen, i - j);
                while (s[j] != s[i]) {
                    exists[s[j]] = false;
                    j++;
                }
                j = j + 1;
            }
            i++;
        }

        return max(maxLen, i - j);
    }
};
*/
