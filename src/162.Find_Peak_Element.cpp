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

//最后跳出的条件是low == high, 此时的low是曾经的mid + 1, 一定满足nums[low/high] > nums[low/high - 1] 而最后的high都是满足着
// > nums[high + 1]的；所以即所求。
//返回high或者low 都可以因为此时两者已经相等。。

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
