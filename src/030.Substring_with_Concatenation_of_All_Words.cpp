class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0 || s.empty())  
            return {};
        int sLen = s.length();
        int wordsCount = words.size();
        int wordLen = words[0].length();
        int wordAllLen = wordLen*wordsCount;
        unordered_map<string, int>  m;
        vector<int> res;
        for (auto w:words) {
            m[w]++;
        }
        for (int i = 0; i <= sLen - wordAllLen; ++i) {
            unordered_map<string, int> found;
            int j = i;
            for (; j < i + wordAllLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (m.find(word) == m.end())
                    break;
                else {
                    found[word]++;
                    if (found[word] > m[word])
                        break;
                }
            }
            if (j == i + wordAllLen)
                res.push_back(i);
        }
        
        return res;
    } //"    "
//[""] 
};
