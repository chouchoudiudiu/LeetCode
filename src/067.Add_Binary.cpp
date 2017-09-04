class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        while(m >= 0 || n >= 0) {
            int sum = carry + (m >= 0 ? a[m--] - '0' : 0) + (n >= 0 ? b[n--] - '0' : 0);
            s = to_string(sum%2) + s;
            carry = sum/2;
        }
        return carry > 0 ? "1" + s : s;
    }
};
