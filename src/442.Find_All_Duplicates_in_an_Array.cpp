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

上面这思路太巧妙。。
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int i = 0, n = nums.size();
        while (i < n) {
            while(nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
            i++;
        }
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) 
                res.push_back(nums[i]);
        }
        return res;
    }
};
