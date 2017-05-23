class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int cnt = 0;
        string res = "";
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] == '-')
                continue;
            if (cnt && cnt%K == 0) //0 % K == 0
                res += '-';
            if (islower(S[i]))
                S[i] = toupper(S[i]);
            res += S[i];
            ++cnt;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
