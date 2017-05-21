class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() == 0 || s.length() < k)
            return 0;
        if (k == 0)
            return s.length();
        int count[26] = {0};
        for (auto c : s)
            ++count[c - 'a'];
        int i = 0;
        while (i < s.length() && count[s[i] - 'a'] >= k)
            ++i;
        if (i == s.length())
            return s.length(); //important!

        int left = longestSubstring(s.substr(0, i), k);
        int right = longestSubstring(s.substr(i + 1), k);
        return max(left, right);
    }
};

/*
in the first pass I record counts of every character in a hashmap
in the second pass I locate the first character that appear less than k times in the string. this character is definitely not included in the result, and that separates the string into two parts (since every char needs to appear more than k times).
keep doing this recursively and the maximum of the left/right part is the answer.
*/
