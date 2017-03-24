class Solution {
public:
    void sortColors(vector<int>& nums) {
        //3way partition
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]); //mid is the location of first possible 1, or value to be checked
            else if (nums[mid] == 1)
                ++mid;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};
