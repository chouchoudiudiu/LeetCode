class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty())
            return 0;
        sort(points.begin(), points.end());
        int res = 1, end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first <= end) {
                end = min(end, points[i].second); //取小的那个，不然的话可能会打不到短的那个，比如之前6结束，一个8结束，若取8，7开始会被以为可以打到
            }
            else {
                ++res;
                end = points[i].second; //a new shot!
            }
        }
        return res;
    }
};
