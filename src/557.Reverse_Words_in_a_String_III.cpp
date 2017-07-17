class Solution {
public:
    string reverseWords(string s) {
        string res = s;
        for(int i = 0, j = 0; i < s.length(); ++i) {
            if(s[i] == ' ') {
                reverse(res, j, i - 1);
                j = i + 1;
            }   
            if(i == s.length() - 1)
                reverse(res, j, i);
        }
        return res;
    }
    
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

