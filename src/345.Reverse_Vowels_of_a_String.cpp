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

/*
s.find_last_of When pos is specified, the search only includes characters at or before position pos, ignoring any possible occurrences after pos.
*/
