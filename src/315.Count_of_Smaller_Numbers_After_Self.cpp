class Solution {
public: //binary search and insert on the fly to generate sorted array O(nlogn)
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted, res;
        for (int i = nums.size() - 1; i >= 0; --i) {//no need to modify nums
            int idx = searchInsert(sorted, nums[i]);
            res.push_back(idx);//where it is inserted indicates how many numbers are smaller than it
            sorted.insert(sorted.begin() + idx, nums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//bit?
