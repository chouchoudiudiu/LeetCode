class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto v : nums1) 
            ++m[v];
        for (auto v : nums2) {
            if (--m[v] >= 0)
                res.push_back(v);
        }
        return res;
    }
};
//if sorted, no space
/*
[1]
[1,1]
*/
