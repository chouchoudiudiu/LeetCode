class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.find_first_not_of(" ");
        int n = s.length(), lastWordLen = 0, start = i;
        bool inWord = true;
        while (i >= 0 && i < n) {
            if (!inWord && s[i] != ' ') {
                start = i;
                inWord = true;
            }
            else if (inWord && s[i] == ' ') {
                lastWordLen = i - start;
                inWord = false;
            }
            ++i;
        }
        
        return (start != -1 && inWord) ? i - start : lastWordLen;
    }
};
