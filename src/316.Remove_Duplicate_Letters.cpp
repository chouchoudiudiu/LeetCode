class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[256] = {0};
        bool placed[256] = {false};
        for (auto c : s) ++cnt[c];
        string res = "0"; //for while
        for (auto c : s) {
            --cnt[c];
            if (placed[c])
                continue; //已经就位
            while (c < res.back() && cnt[res.back()]) { //后面还有机会
                placed[res.back()] = false;//reset
                res.pop_back();//reset
            }
            res += c;
            placed[c] = true;
        }
        return res.substr(1);
    }
};
