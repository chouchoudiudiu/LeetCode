class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int l = 0, r = 0; r < nums.size(); ++r) {
            if(nums[r] != 0) {
                swap(nums[r], nums[l++]);
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for(int r = 0; r < nums.size(); ++r) {
            if(nums[r] != 0)
                nums[l++] = nums[r];
        }
        for(int i = l; i < nums.size(); ++i)
            nums[i] = 0;
    }
};
