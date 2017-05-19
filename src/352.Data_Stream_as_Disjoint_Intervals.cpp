/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval cur(val, val);
        vector<Interval> res;
        int pos = 0;
        for (auto v : intervals) {
            if (cur.end + 1 < v.start) //pos no change, cur.end + 1 == v.start 会连接 [1, 1] [2, 2]
                res.push_back(v);
            else if (cur.start > v.end + 1) {//keep moving to find insert position
                res.push_back(v);
                ++pos;
            }
            else { //overlap
                cur.start = min(cur.start, v.start);
                cur.end = max(cur.end, v.end);
            }
        }

        res.insert(res.begin() + pos, cur); //题中例子最后的pos = 0, cur = [1, 3], 最后的v是唯一push [7, 7]
        intervals = res;
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
    
    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
