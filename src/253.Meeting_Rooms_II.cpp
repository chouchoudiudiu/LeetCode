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

//[[2,11],[6,16],[11,16],[4,12]]
