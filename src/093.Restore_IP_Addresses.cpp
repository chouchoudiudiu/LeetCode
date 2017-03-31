class Solution {
public:
    void restoreIP(vector<string>& res, string s, string out, int start, int part) {
        if (start == s.length() && part == 5) { //start == s.length()
            res.push_back(out);
            return;
        }
        int x = 0; 
        for (int i = start; i < s.length(); ++i) {
            x = x*10 + s[i] - '0';
            if (x <= 255) {
                string tmp = (part == 4) ? to_string(x) : to_string(x) + '.';
                restoreIP (res, s, out + tmp, i + 1, part + 1);
            }
            if (x == 0) //no leading 0s, ok to be single 0
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12 || s.length() < 4) return {};
        string out;
        restoreIP(res, s, out, 0, 1);
        return res;
    }
};
//"12111021121"
