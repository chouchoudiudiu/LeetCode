class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0')
            return *s == '\0';
        if (*(p + 1) != '*') {//must match this character
            return (*p == *s || *p == '.' && *s != '\0') && isMatch(s + 1, p + 1); 
        }
        while (*p == *s || *p == '.' && *s != '\0') {
            if (isMatch(s, p + 2)) //调用递归函数匹配s和去掉前两个字符的p;因为p中a*可以有0或任意个a，可以当做0个
                return true;
            ++s;
        }
        return isMatch(s, p + 2); //not match the first char; such as a... at*
    }
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());       
    }
};
/*
"a"
"af*"
*/
