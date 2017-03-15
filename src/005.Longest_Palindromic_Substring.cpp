class Solution {
public:
    string expandFromCenter(string s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        string longest;
        for (int i = 0; i < s.length(); ++i) {
            string s1 = expandFromCenter(s, i, i);
            if (s1.length() > longest.length()) {
                longest = s1;
            }
            string s2 = expandFromCenter(s, i, i + 1);
            if (s2.length() > longest.length()) {
                longest = s2;
            }
        }
        
        return longest;
    }
};
