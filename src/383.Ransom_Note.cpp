class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[256] = {0};
        for (auto c : magazine) 
            ++mag[c];
        for (auto c : ransomNote) {
            if (--mag[c] < 0)
                return false;
        }
        return true;
    }
};
