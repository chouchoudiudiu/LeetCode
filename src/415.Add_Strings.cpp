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

=======
    
    class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        string s(max(m, n) + 1, '0');
        int sum = 0, carry = 0, i = m - 1, j = n - 1, t = 0;
        while(i >= 0 || j >= 0 || carry > 0) {
            sum = carry + (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
            s[t++] = sum%10 + '0';
            carry = sum/10;
            --i;
            --j; 
        }
        reverse(s.begin(), s.end());
        if(s[0] == '0')
            s.erase(s.begin());
        return s;
    }
};
