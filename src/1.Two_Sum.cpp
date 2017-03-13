class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //num value, index
        for(int i = 0; i < nums.size(); ++i)
        {
            int val = target - nums[i];
            if(m.count(val))
                return {m[val], i}; //1 solution only
            else
                m.insert({nums[i], i});
        }
        return {};
    }
};
