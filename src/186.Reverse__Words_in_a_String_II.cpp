class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); ++i) {
            if(s[i] != ' ') { //a start of a new word
                int j = i;
                while (j < s.length() && s[j] != ' ') //end of the new word
                    ++j;
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
    }
};
