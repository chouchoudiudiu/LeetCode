class Solution {
public:
    bool isNumber(string s) {
        bool space = false;
        bool num = false;
        bool exp = false;
        bool dot = false;
        int i = s.find_first_not_of(' ');
        if (s[i] == '+' || s[i] == '-')
            ++i;
        while (i < s.length()) {
            if (s[i] == ' ')
                space = true;
            else if (space)
                return false; //space inside nonspace
            else if (isdigit(s[i]))
                num = true;
            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !num) //can only have one exp, need to have num before it
                    return false;
                exp = true;
                num = false;// ! need to have num after it
            }
            else if (s[i] == '.') {
                if (exp || dot) //not allow dot after exp or dot
                    return false;
                dot = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if ( s[i - 1] != 'e' )
                    return false;
            }
            else 
                return false;// all other characters
            ++i;
        }
        return num; //need to end by num (or spaces after num)
    }
};
//3.e5 true (like 3.0*e^5)
