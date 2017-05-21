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
