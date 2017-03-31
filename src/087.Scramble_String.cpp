class Solution {
public:
    bool helper (string s1, string s2, map<pair<string, string>, bool>& m) {
        pair<string, string> key = make_pair(s1, s2);
        if (m.count(key) != 0)
            return m[key];
        bool result = false;
        if (s1 == s2)
            return true;
        else if (s1.length() != s2.length())
            return false;
        else {
            for (int i = 1; i < s1.length(); ++i) {
                if ((helper (s1.substr(0, i), s2.substr(0, i), m) && helper (s1.substr(i), s2.substr(i), m)) ||
                (helper (s1.substr(0, i), s2.substr(s2.size() - i), m) && helper (s1.substr(i), s2.substr(0, s2.size() - i), m)))
                { //第二个helper注意是 s2.size() - i 拆分位置
                    result = true;
                    break;
                }
            }
        }
        m[key] = result;
        return result;
    }

    bool isScramble(string s1, string s2) {
        map<pair<string, string>, bool> m; //map, not unordered_map
        return helper (s1, s2, m);
    }
};

    /*
预处理：对于s1,s2的所有位置p1,p2和长度l有子串(p1,p1+l)和(p2,p2+l)，如果两个子串包含不同的字符集则搜索时不予考虑
搜索：对于s1,s2，以及可能的字串长度l，递归搜索以下两种情况：
把s1和s2拆成l和strlen(s1)-l两段，分别递归搜索
把s1拆成l和strlen(s1)-l两段，把s2拆成strlen(s2)-l和l两段，分别递归搜索 */
