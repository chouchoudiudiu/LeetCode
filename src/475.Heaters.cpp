class Solution {
public:
//每一个house找和他最近位置比它大的heater，找不到就用heaters最大的，这样保证每个house都能cover到
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (auto house : houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), house); //basically binary search, lowerbound >=; upperbound >
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos); //house一定大于它，因为后一个是第一个大等于house的
            radius = max(radius, min(dist1, dist2));
        }
        return radius;
    }
};

//1234 [1,4];1 好理解，2先算到 *pos = 4，再看 *(--pos) == 1
