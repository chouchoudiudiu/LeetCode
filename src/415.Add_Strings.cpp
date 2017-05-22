class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0, i = 0, maxLen = max(len1, len2);
        string res(maxLen + 1, '0');
        while (i < maxLen) {
            int sum = carry + (i < len1 ? num1[i] - '0': 0) + (i < len2 ? num2[i] - '0': 0); //- '0'; carry +
            res[i++] = sum%10 + '0';
            carry = sum/10;
        }
        if (carry > 0) res[i] = carry + '0'; // don't forget about the carry!
        reverse(res.begin(), res.end());
        if (res[0] == '0')
            res.erase(res.begin());
        return res;
    }
};
