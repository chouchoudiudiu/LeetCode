class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) { //make sure mid + 1 is valid
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
                high = mid; //what we are searching may be mid
            else
                low = mid + 1; //can be mid
        }
        return high;
    }
};

/////////////////////////////////////////
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return i - 1;
        }
        return nums.size() - 1; //mono increasing
    }
};
