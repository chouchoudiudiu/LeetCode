class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxCount = 0;
        for (auto v:nums) {
            set.erase(v);
            int val = v;
            int count = 1;
            while (set.count(++val)) {
                set.erase(val);
                ++count;
            }
            while (set.count(--v)) {
                set.erase(v);
                ++count;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
