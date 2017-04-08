/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n == 0) return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> m; //key为pair必须用map
            int duplicate = 1, maxCountForI = 0;
            for (int j = i + 1; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) //之前通过j的线已经算过
                    ++duplicate;
                else {
                    int dx = points[j].x - points[i].x;
                    int dy = points[j].y - points[i].y;
                    int d = gcd(dx, dy);
                    ++m[{dy/d, dx/d}]; //avoiding divide on
                }
            }
            for (auto it = m.begin(); it != m.end(); ++it)
                maxCountForI = max(maxCountForI, it->second); //m size can be 0
            res = max(maxCountForI + duplicate, res);
        }
        return res;
    }
};
//[[0,0],[94911151,94911150],[94911152,94911151]] float, double has problem when used in map as a key
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n == 0) return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<float, int> m;
            int duplicate = 1, maxCountForI = 0;
            for (int j = i + 1; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) //之前通过j的线已经算过
                    ++duplicate;
                else if (points[i].x == points[j].x)//vertical
                    ++m[INT_MAX];
                else {
                    float slope = (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    ++m[slope];
                }
            }
            for (auto it = m.begin(); it != m.end(); ++it)
                maxCountForI = max(maxCountForI, it->second); //m size can be 0
            res = max(maxCountForI + duplicate, res);
        }
        return res;
    }
};
//[[0,0],[94911151,94911150],[94911152,94911151]] float, double has problem when used in map as a key
