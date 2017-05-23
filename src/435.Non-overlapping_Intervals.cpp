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
//Greedy
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() <= 1)
            return 0;
            sort(intervals.begin(), intervals.end(), [](const Interval&  a, const Interval& b) {
                return a.start == b.start ? a.end < b.end : a.start < b.start;
            });
        int cnt = 0, prev = 0, curr = 1;
        while (curr < intervals.size()) {
            if (intervals[prev].end <= intervals[curr].start)
                prev = curr;
            else { //>, overlap exists! remove the later one sicne it has high chance to overlap with next intervals
                if (intervals[prev].end > intervals[curr].end)
                    prev = curr; //很重要！如果两个Interval有重合，去掉那个end大的！
                ++cnt;
            }
            curr++;
        }
        return cnt;
    }
};
