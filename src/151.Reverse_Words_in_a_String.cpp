class Solution {
public:
    void reverseWords(string &s) {
        int index = 0, n = s.length();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {//a start of a new word
                if (index != 0) s[index++] = ' ';//append a space after a word
                int j = i;
                while (j < n && s[j] != ' ')
                    s[index++] = s[j++]; //copy word
                reverse(s.begin() + index - (j - i), s.begin() + index); //end is past last char
                i = j;
            }
        }
        s.resize(index);
    }
};

//" "; "   "; "1 "
//string s = "     a      ";
