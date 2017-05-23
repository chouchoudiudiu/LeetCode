class Solution {
public:
//greedy
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            res[i] = i + 1;
        int i = 0;
        while (i < n) {
            if (s[i] == 'D') {
                int j = i;
                while (i < n && s[i] == 'D')
                    ++i;
                reverse(res.begin() + j, res.begin() + i + 1);
            }
            else
                ++i;
        }
        return res;
    }
};

/*
我们需要记录D的起始位置i，还有D的连续个数k，那么我们只需要在数组中倒置[i, i+k]之间的数字即可
*/
