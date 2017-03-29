class Solution {
public:
    bool helper(vector<int>& nums, int low, int high, int target) {
        if (low > high)
            return false;
        int mid = low + (high - low)/2;
        if (target == nums[mid])
            return true;
        if (nums[low] < nums[mid]) { //left sorted 
            if (nums[low] <= target && target < nums[mid])
                return helper (nums, low, mid - 1, target);
            else
                return helper (nums, mid + 1, high, target);
        }
        else if (nums[low] > nums[mid]) { //right sorted
            if (nums[mid] < target && nums[high] >= target)
                return helper (nums, mid + 1, high, target);
            else
                return helper (nums, low, mid - 1, target);
        }
        else { // nums[low] == nums[mid] 222342 31233333
            return helper (nums, low, mid - 1, target) || helper (nums, mid + 1, high, target);
        }
    }
    bool search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};
