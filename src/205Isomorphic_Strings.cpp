class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, rm; //from s -> t and from t -> s
        for (int i = 0; i < s.length(); ++i) {
            if (m.find(s[i]) == m.end()) {
                if (rm.find(t[i]) != rm.end()) //t[i] has been used by other character in s
                    return false;
                else {
                    m[s[i]] = t[i]; //including self
                    rm[t[i]] = s[i];
                }
            }
            else {
                if (m[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
