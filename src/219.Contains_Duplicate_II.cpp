class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) 
                set.erase(nums[i - k - 1]); //expire
            if (set.find(nums[i]) != set.end())
                return true;
            set.insert(nums[i]);
        }
        return false;
    }
};
