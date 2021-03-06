class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        unordered_map<char, string> m1;
        unordered_map<string, char> m2; //can reduce to one map, need to iterate m1 to make sure other word's second is not token
        int i = 0;
        for (string token; ss >> token; ++i) {
            if (m1.find(pattern[i]) == m1.end()) {
                if (m2.find(token) != m2.end())//used by other char
                    return false;
                else {//insert
                    m1.insert({pattern[i], token});
                    m2.insert({token, pattern[i]});
                }
            }
            else {
                if (m1[pattern[i]] != token)
                    return false;
            }
        }
        return i == pattern.size();
    }
};

//almost the same as Isomorphic Strings
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int i = 0;
        for(string token; ss >> token; ++i) {
            if(i >= pattern.size())
                return false;
            char c = pattern[i];
            if(m1.find(c) == m1.end()) {
                if(m2.find(token) != m2.end())
                    return false;
                else {
                    m1[c] = token;
                    m2[token] = c;
                }
            }
            else {
                if(m1[c] != token)
                    return false;
            }
        }
        return i == pattern.size();
    }
};
