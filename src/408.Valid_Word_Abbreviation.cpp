class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0')
                    return false; //no zero or leading zero, 10 is okay inside while
                int val = 0; 
                while (isdigit(abbr[j])) 
                    val = val*10 + abbr[j++] - '0';
                i += val;
            }
            else if (word[i++] != abbr[j++])
                return false;
        }   
        return i == word.size() && j == abbr.size();
    }
};
/*
"a"
"01"
*/
