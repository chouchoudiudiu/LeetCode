class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0, i = 0, maxLen = max(len1, len2);
        string res;
        while (i < maxLen) {
            int sum = carry + (i < len1 ? num1[i] - '0' : 0) + (i < len2 ? num2[i] - '0' : 0);
            res += sum%10 + '0';
            carry = sum/10;
            i++;
        }
        if(carry > 0)
            res += carry + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};
