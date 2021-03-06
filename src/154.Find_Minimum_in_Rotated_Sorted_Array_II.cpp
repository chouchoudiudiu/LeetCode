class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() < 1)
            return -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high && nums[low] >= nums[high]) { //okay to use low <= high or low < high?
            if (nums[low] == nums[high]) {//can't add -- here
                --high;
                continue;
            }
            int mid = low + (high - low)/2;
            if (nums[mid] <= nums[high]) //<=
                high = mid; //mid still possible
            else
                low = mid + 1;
        }
        return nums[low];
    }
};
