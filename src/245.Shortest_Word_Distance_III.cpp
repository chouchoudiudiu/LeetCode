class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1, pos3 = -1, minD = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i])
                pos1 = i;
            if (word1 != word2) {
                if(word2 == words[i])
                    pos2 = i;
                if (pos1 != -1 && pos2 != -1) 
                    minD = min(minD, abs(pos1 - pos2));
            }
            else { //word1 == word2
                if(words[i] == word1) {
                    if(pos3 != -1) //not the first time meet
                        minD = min(minD, i - pos3);
                    pos3 = i; //last time it sees a duplicate
                }
            }
        }
        return minD;
    }
};
