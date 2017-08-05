class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1; //之前判断过，s[0]一定不是0到这里
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = (s[i - 1] == '0') ? 0:dp[i - 1];//不可以是0,除非是10,20,要再看前一位
            if (i > 1 && (s[i - 2] == '1' || s[i - 1] <= '6' && s[i - 2] == '2'))
                dp[i] += dp[i - 2];
        }
        return dp.back(); //dp[i]表示使用了i个字母得到的表达数目 2512 第一种是用2，看215的表达，第二种是用12，看25的表达；即在之前结果分别
        //添加 B与L; 如果求12，就是(dp[1] = 1) + (dp[0] = 1); 92就没有后面一项
    }
};

//could reduce space further
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        int c1 = 1, c2 = 1; // c2: decode ways of s[i-2] , c1: decode ways of s[i-1] 
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] == '0')
                c1 = 0; //zero voids ways of the last because zero cannot be used separately
            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                c1 = c1 + c2; // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
                c2 = c1 - c2; //old c1
            }
            else
                c2 = c1; // one-digit letter, no new way added
        } 
        return c1;
    }
};
//'12'
