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