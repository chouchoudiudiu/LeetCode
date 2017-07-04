class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n);
        unordered_map<int, int> m; //score, pos
        for(int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n; ++i) {
            int pos = m[nums[i]];
            if(i == 0)
                res[pos] = "Gold Medal";
            else if(i == 1)
                res[pos] = "Silver Medal";
            else if(i == 2)
                res[pos] = "Bronze Medal";
            else
                res[pos] = to_string(i + 1);
        }
        return res;
    }
};
