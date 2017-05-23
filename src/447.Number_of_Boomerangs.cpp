class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int cnt = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<long, int> m;//.first distance; .second count of such distance from points[i]
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    long dist2 = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2); 
                    m[dist2]++;//all int so long
                }
            }
            for (auto v : m) {
                if (v.second >= 2)
                    cnt += v.second*(v.second - 1); // /2 * 2
            }
        }
        return cnt;
    }
};


//[[0,0],[2,0],[-1,2], [0,2],[1,1]]
