class Solution {
public:
    int lengthOfLastWord(string s) {
        bool inWord = false;
        int len = 0, start = -1, i = 0;
        for(i = 0; i < s.length(); ++i) {
            if(inWord && s[i] == ' ') {
                len = i - start;
                inWord = false;
            }
            if(!inWord && s[i] != ' ') {
                start = i;
                inWord = true;
            }
        }
        return inWord ? (i - start) : len;
    }
};

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

///cleaner

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, start = 0;
        bool inside = false;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == ' ' && inside) {
                len = i - start;
                inside = false;
            }
            if(s[i] != ' ' && !inside){
                start = i;
                inside = true;
            }
        }

        return inside ? s.length() - start : len;
    }
};
