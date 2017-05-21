class Solution {
public:
//all the char that occurs even times can enroll, and then the largest odd number;不对，不需要都用的
    int longestPalindrome(string s) {
        int maxLen = 0;
        bool hasOdd = false;
        int cnt[256] = {0};
        for (auto c : s) 
            cnt[c]++;
        for (int i = 0; i < 256; ++i) {
            if (cnt[i]%2 == 0)
                maxLen += cnt[i];
            else {
                maxLen += cnt[i] - 1;
                hasOdd = true;
            }
        }
        return maxLen + (hasOdd ? 1 : 0);
    }
};
