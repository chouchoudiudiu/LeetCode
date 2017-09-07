class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto s : strs)
            res += to_string(s.length()) + "#" + s; // +=, not push_back
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t last = -1;
        size_t found = s.find_first_of("#");
        while (found != string::npos) {
            int len = stoi(s.substr(last + 1, found - last - 1));
            string str = s.substr(found + 1, len);
            last = found + len;
            found = s.find_first_of("#", last + 1);
            strs.push_back(str);
        }
        return strs;
    }
};
//len1#real1len2#real2
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
