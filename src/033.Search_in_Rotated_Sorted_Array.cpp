class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid]) { //left half sorted, be careful with <= due to round off, low == mid
                if (nums[mid] > target && nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                if (nums[mid] < target && nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
//[3,1]
//1
