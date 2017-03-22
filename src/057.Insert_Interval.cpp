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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        bool merge_done = false;
        for (auto v:intervals) {
            if (v.start <= newInterval.end && v.end >= newInterval.start) {//has overlap
                newInterval.start = min(v.start, newInterval.start);
                newInterval.end = max(v.end, newInterval.end);
                continue; //check next interval, might need to be merged too
            }
            if (!merge_done && newInterval.end < v.start ) {//only need to merge once!
                res.push_back(newInterval);
                merge_done = true;
            }
            res.push_back(v); //all elements without overlap
        }
        if (!merge_done)
            res.push_back(newInterval); // last item
        return res;
    }
};
