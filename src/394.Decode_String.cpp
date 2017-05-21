class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> strs;
        string res;
        int i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int n = 0;
                while (isdigit(s[i])) {
                    n = n * 10 + s[i++] - '0';
                }
                cnt.push(n);
                continue;
            }
            else if (s[i] == '[') {//frist is "", useless
                strs.push(res);
                res = "";
            }
            else if (s[i] == ']') {
                string tmp = res;
                res = strs.top(); 
                strs.pop();
                int n = cnt.top();
                cnt.pop();
                for (int j = 0; j < n; ++j)
                    res += tmp; //加在右边
            }
            else {
                res += s[i];
            }
            ++i;
        }
        return res;
    }
};
//"2[t2[abc]3[cd]ef]"
