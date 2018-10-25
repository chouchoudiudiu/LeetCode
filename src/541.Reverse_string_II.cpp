class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length(), i = 0;
        while(i < n) {
            int j = min(n - i, k);
            reverse(s, i, i + j - 1);
            i += 2*k;
        }
        return s;
    }
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};


=======
    class Solution {
public:
    string reverseStr(string s, int k) {
        string res;
        int n = s.length();
        for(int i = 0; i < n; i += 2*k) {
            if(i + k <= n) {
                string tmp = s.substr(i, k);
                reverse(tmp.begin(), tmp.end());
                res += tmp + s.substr(i + k, min(k, n - i));
            }
            else {
                string tmp = s.substr(i);
                reverse(tmp.begin(), tmp.end());
                res += tmp;
            }
        }
        return res;
    }
};
