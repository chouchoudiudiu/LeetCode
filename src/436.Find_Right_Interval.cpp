/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res, nums;
        unordered_map<int, int> m;//store start and index pair
        for (int i = 0; i < intervals.size(); ++i) {
            m.insert({intervals[i].start, i});
            nums.push_back(intervals[i].start);
        }
        sort(nums.begin(), nums.end());
        for (auto v : intervals) {
            int idx = binarySearch(nums, v.end); //v.end
            if (idx == -1)
                res.push_back(-1);
            else
                res.push_back(m[nums[idx]]);
        }
        return res;
    }
    int binarySearch (vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (target > nums.back())
            return -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] >= target) //>=
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
};
