class Solution {
public:
    string rangeToString(int lower, int upper) {
        if (lower == upper)
            return to_string(lower);
        else
            return to_string(lower) + "->" + to_string(upper);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) {
            return {rangeToString(lower, upper)};
        }
        if (nums[0] != lower) {
            res.push_back(rangeToString(lower, nums[0] - 1));
        }
        for (int i = 0; i < n - 1; ++i) { //starting from 0
            if ((long long)nums[i + 1] > (long long)nums[i] + 1) //has gap //nums[i] != INT_MAX
                res.push_back(rangeToString(nums[i] + 1, nums[i + 1] - 1));
        }
        if (nums[n - 1] != upper) {
            res.push_back(rangeToString(nums[n - 1] + 1, upper));
        }
        return res;
    }
};

/*
[-2147483648,-2147483648,0,2147483647,2147483647]
-2147483648
2147483647
*/
