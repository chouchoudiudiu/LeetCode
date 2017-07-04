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
