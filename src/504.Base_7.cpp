class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        bool neg = (num < 0);
        if (neg)
            num*= (-1);
        string res = "";
        while (num > 0) {
            res += to_string(num%7);
            num /= 7;
        }
        if (neg)
            res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};

=======
    class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        //long n = num;
        bool neg = false;
        if(num < 0) {
            neg = true;
            num = -num;
        }
        string s;
        while(num > 0) {
            s += num%7 + '0';
            num /= 7;
        }
        reverse(s.begin(), s.end());
        return neg ? "-" + s : s;
    }
};
