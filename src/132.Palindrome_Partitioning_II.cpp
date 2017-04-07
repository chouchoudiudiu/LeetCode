class Solution {
public:
//一定有解，最差就是每个字母为一个cut
    int minCut(string s) {
        int len = s.length();
        vector<vector<bool>> pal(len, vector<bool>(len, false)); //start end matrix
        vector<int> dp(len + 1, 0);
        for (int i = 0; i < len; ++i) //i, i + 0
            pal[i][i] = true;
        for (int i = 0; i < len - 1; ++i) { //i, i + 1
            if (s[i] == s[i + 1])
                pal[i][i + 1] = true;
        }
        for (int length = 2; length < len; ++length) //i, i + 2, i + 3, i + len
            for (int i = 0; i + length < len; ++i) {
                if (s[i] == s[i + length] && pal[i + 1][i + length - 1])
                    pal[i][i + length] = true;
            }
        for (int i = 1; i <= len; ++i) { //number of chars involved
            int dmin = INT_MAX;
            for (int j = 0; j <= i - 1; ++j) { //valid j index
                if (pal[j][i - 1]) 
                    dmin = min(dmin, dp[j] + 1); //在j处切，如果从char j到char i - 1是pal, 那么就是d[j] + 1
            }
            dp[i] = dmin;
        }
        return dp[len] - 1; //the last cut is at the right of last char
    }
};
