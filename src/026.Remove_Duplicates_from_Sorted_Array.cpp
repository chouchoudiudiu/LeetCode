class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)   
            return 0;
        int val = nums[0];
        int i = 0, j = 1;
        while (++i < nums.size()) {
            if (val != nums[i]) {
                val = nums[i];
                nums[j++] = val;
            }
        }
        nums.resize(j);
        return j;
    }
};
