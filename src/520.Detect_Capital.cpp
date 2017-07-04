class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto c : word) {
            if (isupper(c))
                ++cnt;
        }
        return cnt == word.size() || (cnt == 1 && isupper(word[0])) || cnt == 0;
    }
};
