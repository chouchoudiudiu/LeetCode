class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto v : nums2) {
            if (m.find(v) != m.end()) {
                res.push_back(v);
                m.erase(v);
            }
        }
        return res;
    }
};
