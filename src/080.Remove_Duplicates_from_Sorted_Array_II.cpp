class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int val = nums[0], count = 1, j = 1, i = 0;
        while (++i < nums.size()) {
            if (nums[i] == val && count < 2) {
                ++count;
                nums[j++] = val;
            }
            else if (nums[i] != val) {
                val = nums[i];
                nums[j++] = val;
                count = 1;
            }
        }
        nums.resize(j);
        return j;
    }
};
