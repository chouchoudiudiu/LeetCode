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


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                res.insert(nums1[i]);
                ++i;
                ++j;
            }
            else if(nums1[i] < nums2[j])
                ++i;
            else
                ++j;
        }
        return vector<int>(res.begin(), res.end());
    }
};
