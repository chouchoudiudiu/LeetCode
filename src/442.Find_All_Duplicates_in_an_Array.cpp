class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};
//-4 3 2 -7 8 2 -3 -1 
//对于每个nums[i]，我们将其对应的nums[nums[i] - 1]取相反数，如果其已经是负数了，说明之前存在过
