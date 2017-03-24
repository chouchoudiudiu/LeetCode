class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int v1 = m >= 0 ? a[m--] - '0' : 0;
            int v2 = n >= 0 ? b[n--] - '0' : 0;
            int sum = v1 + v2 + carry;
            res = to_string(sum%2) + res;
            carry = sum/2;
        }
        return carry > 0 ? "1" + res : res;
    }
};
