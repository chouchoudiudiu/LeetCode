class Solution {
public:
    int searchLeft (vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (nums[0] == target)
            return 0; //note
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target && nums[mid - 1] < target)// exactly what we are looking for
                return mid;
            if (nums[mid] >= target) //mid非所求否则上一个if就满足，mid为target却不满足大于左边，则左边也target
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
    int searchRight (vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (nums[high] == target)
            return high; //note
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target && nums[mid + 1] > target)// right of mid can have several target
                return mid;
            if (nums[mid] <= target) //!
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res; //note
        res[0] = searchLeft(nums, target);
        res[1] = searchRight(nums, target);
        return res;
    }
};

/*
[0,0,0,2,2,2,2,2,2,3,4,5,5,5,6,7,9,9,9,9,10,11,12]
9

[0,0,1,2,2]
2
*/
