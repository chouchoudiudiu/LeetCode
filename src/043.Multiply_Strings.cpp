class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0 || len2 == 0) return "";
        if (num1 == "0" || num2 == "0") return "0";
        
        string res(len1 + len2, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < len2; ++i) {
            int carry = 0;
            int val2 = num2[i] - '0';
            for (int j = 0; j < len1; ++j) {
                int val1 = num1[j] - '0';
                int tmp = res[i + j] - '0' + val1*val2 + carry; //注意由之前算过的值
                res[i + j] = tep%10 + '0';
                carry = tmp/10;
            }
            if (carry > 0)
                res[len1 + i] = carry + '0'; //inside! 注意是len1 + i
        }
        if(res.back() == '0')
            res.pop_back();
        return string(res.rbegin(), res.rend());
    }
};
