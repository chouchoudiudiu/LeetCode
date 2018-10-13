class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for(auto c : s) {
            if(c == 'A')
                ++a;
            if(c == 'L')   //注意这里不是else if....因为下一个语句！只要不是l（a or p） 则l全部清0
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
            if(i >= 2 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') //not adaptable!
                return false;
        }
        return true;
    }
};

=====
    
太啰嗦
class Solution {
public:
    bool checkRecord(string s) {
        int start = -1, cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == 'A') {
                ++cnt;
                if(cnt == 2) 
                    return false;
                start = -1;
            }
            else if(s[i] == 'L') {
                if(start == -1) 
                    start = i;
                if(i - start == 2)
                    return false;
            }
            else
                start = -1;
        }
        return true;
    }
};
