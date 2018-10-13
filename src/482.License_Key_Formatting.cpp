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


//////////
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int cnt = 0;
        for(int i = S.length() - 1; i >= 0; --i) {
            if(S[i] == '-')
                continue;
            if(cnt == K) {
                res.insert(res.begin(), '-');
                cnt = 0;
            }
            res.insert(res.begin(), toupper(S[i]));
            ++cnt;
        }
        return res;
    }
};
