/*auto cmp = [](const pair<int, int>& a, const pair<int, int>& b)
{
  return (a.first + a.second) < (b.first + b.second);
};*///both okay

class Solution {
public:

    struct comp{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second; //maxheap
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size(); ++j) {
                if (pq.size() < k)
                    pq.push({nums1[i], nums2[j]});
                else if ( nums1[i] + nums2[j] < pq.top().first + pq.top().second ) {
                    pq.push({nums1[i], nums2[j]});
                    pq.pop();
                }
            }
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res; //order doesn't matter, reverse if you want sorted
    }
};
