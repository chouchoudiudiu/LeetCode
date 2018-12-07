class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int xMin = INT_MAX, xMax = INT_MIN;
        for (auto v : points) {
            xMin = min(xMin, v.first);
            xMax = max(xMax, v.first);
        }
        set<pair<int, int>> m(points.begin(), points.end()); //pair can't be used in unordered_set
        double mid = (double)(xMin + xMax)/2;
        for (auto v : points) {
            double diff = abs(v.first - mid);
            if (v.first < mid && m.find({mid + diff, v.second}) == m.end())
                return false;
            if (v.first > mid && m.find({mid - diff, v.second}) == m.end())
                return false;
        }
        return true;
    }
};

//[[0,0],[1,0]]
//[[1,1],[-4,1]]
// https://stackoverflow.com/questions/30419681/why-cant-i-use-pair-as-key-of-unordered-set-unordered-map
