class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size(), i = 0;
        for (i = n; i >= 0; --i) {
            if (s.substr(0, i) == t.substr(n - i)) //from n - i to the rest
                break;
        }
        return t.substr(0, n - i) + s;// if i == 0, complete flipped s
    }
};

//s去掉最后一位，t去掉第一位，继续比较
//brute force abbacd 应该是在字符串前面依次增加，[d]abbacd, [dc]abbacd, [dca]abbacd看构成的字符串是否是回文
