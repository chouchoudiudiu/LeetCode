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
//最多有几个同时进行的会议，则最多需要几个房间
 //room is equal to number of active meetings
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starts(n, 0);
        vector<int> ends(n, 0);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int room = 0;
        for(int i = 0, j = 0; i < n; ++i){
            if (starts[i] < ends[j]) //need parallel rooms
                ++room;
            else 
                ++j; //room released, the room can immediately start a new meeting
        }
        return room;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        }); //也是必须的
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto v : intervals) {
            if(!pq.empty() && v.start >= pq.top())
                pq.pop();
            pq.push(v.end);
        }
        return pq.size();
    }
};
/*
这种方法先把所有的时间区间按照起始时间排序，然后新建一个最小堆，开始遍历时间区间，如果堆不为空，
且首元素小于等于当前区间的起始时间，我们去掉堆中的首元素，把当前区间的结束时间压入堆，
由于最小堆是小的在前面，那么假如首元素小于等于起始时间，说明上一个会议已经结束，
可以用该会议室开始下一个会议了，所以不用分配新的会议室，遍历完成后堆中元素的个数即为需要的会议室的个数

按开始时间排序是必须的，这样才能说前面的一个会议已经结束了
*/
