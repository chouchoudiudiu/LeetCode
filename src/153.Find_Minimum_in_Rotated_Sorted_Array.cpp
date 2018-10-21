class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() < 1)
            return -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high && nums[low] > nums[high]) { //okay to use low <= high or low < high
            int mid = low + (high - low)/2;
            if (nums[mid] < nums[high])
                high = mid; //mid still possible
            else
                low = mid + 1;
        }
        return nums[low];
    }
};


======
    class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low <= high && nums[low] > nums[high]) {
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
