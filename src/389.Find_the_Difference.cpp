class Solution {
public:
    char findTheDifference(string s, string t) {
        //like single number. xor
        int x = 0;
        for (auto c : s)
            x ^= c;
        for (auto c : t)
            x ^= c;
        return x;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq_s[26] = {0};
        int freq_t[26] = {0};
        for(auto c : s) 
            ++freq_s[c - 'a'];
        for(auto c : t) {
            if(++freq_t[c - 'a'] > freq_s[c - 'a'])
                return c;
        }
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0};
        for(auto c : s) 
            ++freq[c - 'a'];
        for(auto c : t) {
            if(--freq[c - 'a'] < 0)
                return c;
        }
    }
};
