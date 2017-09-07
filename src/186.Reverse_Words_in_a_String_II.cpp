class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        reverse(s, 0, n - 1);
        for(int i = 0, j = 0; i < n; ++i) {
            if(s[i] == ' ') {
                reverse(s, j, i - 1);
                j = i + 1;
            }
            if(i == n - 1) 
                reverse(s, j, i);
        }
    } 
    void reverse(string& s, int l, int r) {
        while(l < r)
            swap(s[l++], s[r--]);
    } 
};

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
