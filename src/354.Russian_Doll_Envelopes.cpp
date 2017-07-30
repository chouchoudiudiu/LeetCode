class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int maxSize = 0; //at least one self
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxSize = max(maxSize, dp[i]);
        }
        return maxSize;
    }
};

//optimize
