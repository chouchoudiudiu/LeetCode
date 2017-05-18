class Solution {
public:
    bool canWin(string s) {
        if (s.length() < 2)
            return false;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                string t = s.substr(0, i - 1) + "--" + s.substr(i + 1);
                if (!canWin(t)) //check opponent
                    return true;
            }
        }
        return false; //no move can be taken
    }
};
