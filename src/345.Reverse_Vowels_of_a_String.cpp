class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            l = s.find_first_of("aeiouAEIOU", l);
            r = s.find_last_of("aeiouAEIOU", r);
            if (l < r)
                swap(s[l++], s[r--]);
        }
        return s;
    }
};
