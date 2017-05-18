class Solution {
public:
    bool helper(string pattern, int p, string str, int s, unordered_map<char, string> &m) {
        if (p == pattern.size() && s == str.size())
            return true;
        if (p == pattern.size() || s == str.size()) //表示另外一个不满足完成
            return false;
        char c = pattern[p];
        for (int i = s; i < str.size(); ++i) { //loop through str
            string word = str.substr(s, i - s + 1);
            if (m.count(c) && m[c] == word) {
                if(helper(pattern, p + 1, str, i + 1, m))    
                    return true; //even false, still have chance for other i, dont' return helper()
            }
            else if(!m.count(c)) { //count(c)且不等的直接跳过了
                bool used = false;
                for (auto v : m) {
                    if (v.second == word)
                        used = true;
                }
                if (!used) {
                    m.insert({c, word}); //or m[c] = word
                    if (helper(pattern, p + 1, str, i + 1, m))
                        return true;
                    else
                        m.erase(c);
                }               
            }
        }
        return false; //no further possible exploration
    }
    
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        return helper(pattern, 0, str, 0, m);
    }
};
/*
"abcd" or "abcdef"
"redblueredblue" true (can be a matching first -3 letters)
"ab"
"redred" true (a match redre)
//ab, aa false
*/
