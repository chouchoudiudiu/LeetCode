class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0, j = 0; i < s.length(); ++i) {
            if(s[i] == ' ') {
                reverse(s, j, i - 1);
                j = i + 1;
            }   
            if(i == s.length() - 1)
                reverse(s, j, i);
        }
        return s;
    }
    
    void reverse(string& s, int l, int r) {
        while(l < r) 
            swap(s[l++], s[r--]);
    }
};
    
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

    string reverseWords(string s) {
        bool inWord = true;
        for(int i = 0, j = 0; i < s.length(); ++i) { //j is the start position
            if(i == s.length() - 1 || s[i + 1] == ' ') {
                reverse(s, j, i);
                j = i + 2;
            }
        }
        return s;
    }
