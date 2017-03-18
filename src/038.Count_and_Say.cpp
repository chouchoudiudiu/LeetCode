class Solution {
public:
    string helper(string s)
    {
        string res = "";
        int cnt = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (i < s.length() - 1 && s[i] == s[i + 1]) //i < s.length() - 1
                ++cnt;
            else {
                res += to_string(cnt) + s[i];
                cnt = 1;
            }
        }
        return res;
    }
    
    string countAndSay(int n) {
        string s = "1";
        while(--n > 0) {
            s = helper(s);
        }
        return s;
    }
};
