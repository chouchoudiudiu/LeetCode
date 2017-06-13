class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c : s)
            ++m[c];
        bool found = false;
        for(auto v : m) {
            if(v.second%2) {
                if(found)
                    return false;
                else
                    found = true;
            }
        }
        return true;
    }
};
