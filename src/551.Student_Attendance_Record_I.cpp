class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for(auto c : s) {
            if(c == 'A')
                ++a;
            if(c == 'L')
                ++l;
            else
                l = 0;
            if(a >= 2 || l > 2)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool checkRecord(string s) {
        int Acnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == 'A')
                ++Acnt;
            if(Acnt > 1)
                return false;
            if(i >= 2 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')
                return false;
        }
        return true;
    }
};
