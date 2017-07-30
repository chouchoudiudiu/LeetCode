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
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return (a.first == b.first) ? a.second > b.second : a.first < b.first;});
        vector<int> vec;
        for(auto v : envelopes) {
            auto pos = lower_bound(vec.begin(), vec.end(), v.second);
            if(pos == vec.end())
                vec.push_back(v.second);
            else 
                *pos = v.second;
        }
        return vec.size();
    }
};

//完全一样的呢？
//[[4,5],[6,7],[2,3]]
//要考虑一下LIS中如果允许可以相等的情况，该如何改变？
/*我们还可以使用二分查找法来优化速度，我们首先要做的还是给信封排序，但是这次排序和上面有些不同，信封的宽度还是从小到大排，但是宽度相等时，我们让高度大的在前面。那么现在问题就简化了成了找高度数字中的LIS，完全就和之前那道Longest Increasing Subsequence一样了
*/
