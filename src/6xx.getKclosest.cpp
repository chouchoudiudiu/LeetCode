/*
给定N个坐标Point，每个Point实例有x-坐标和y-坐标。题目要求函数返回离原点最近的k个坐标。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

struct Point {
    double x;
    double y;
    Point(double a, double b) {
        x = a;
        y = b;
    }
};

double getDist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Point global_origin = Point(0, 0);

struct comp {
    bool operator() (const Point& a, const Point& b) {
        return getDist(a, global_origin) < getDist(b, global_origin);
    }
};

vector<Point> kClosest(vector<Point>& array, Point origin, int k) {
    global_origin = Point(origin.x, origin.y);
    priority_queue<Point, vector<Point>, comp> pq;  //maxheap
    vector<Point> res;
    for(auto p : array) {
        if(pq.size() < k)
            pq.push(p);
        else {
            if(getDist(p, global_origin) < getDist(pq.top(), global_origin)) {
                pq.pop();
                pq.push(p);
            }
        }
    }
    while(!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int main()
{
   Point p1 = Point(4.5, 6.0);
   Point p2 = Point(4.0, 7.0);
   Point p3 = Point(4.0, 4.0);
   Point p4 = Point(2.0, 5.0);
   Point p5 = Point(1.0, 1.0);
   vector<Point> array = {p1, p2, p3, p4, p5};
   int k = 2;
   Point origin = Point(0.0, 0.0);
   vector<Point> ans = kClosest(array, origin, k);
   for (int i = 0; i < ans.size(); i++) {
       cout << i << ": " << ans[i].x << "," << ans[i].y << endl;
   }
   //cout << getDistance(p1, p2) << endl;
}

//time: O(NlogK)
//space: O(K)
