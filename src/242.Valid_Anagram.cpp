class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if (l1 != l2)
            return false;
        int freq[26] = {0};
        for (auto c : s)
            freq[c - 'a']++;
        for (auto c : t) {
            if(--freq[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
