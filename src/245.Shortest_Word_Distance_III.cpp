class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1, minD = INT_MAX;
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1)
                pos1 = i;
            if(word1 != word2) {
                if(words[i] == word2)
                    pos2 = i;
                if(pos1 != -1 && pos2 != -1)
                    minD = min(minD, abs(pos1 - pos2));
            }
            else { //word1 == word2
                if(words[i] == word1) {
                    if(pos2 != i && pos1 != -1 && pos2 != -1) //not the first time meet
                        minD = min(minD, pos1 - pos2); //pos1 is fresher
                    pos2 = i;   //last time it sees a duplicate
                }
            }
        }
        return minD;
    }
};
