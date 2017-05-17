class Solution {
public:
//or use unordered_map
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1, minD = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i])
                pos1 = i;
            if (word2 == words[i])
                pos2 = i;
            if (pos1 != -1 && pos2 != -1) {
                minD = min(minD, abs(pos1 - pos2));
                if (minD == 1)
                    return 1;
            }
        }
        return minD;
    }
};
