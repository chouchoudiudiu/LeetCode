class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        for(int i = 0; i < n; ++i) {
            string t1 = timePoints[i], t2 = timePoints[(i + 1)%n];
            int h1 = (t1[0] - '0')*10 + (t1[1] - '0');
            int m1 = (t1[3] - '0')*10 + (t1[4] - '0');
            int h2 = (t2[0] - '0')*10 + (t2[1] - '0');
            int m2 = (t2[3] - '0')*10 + (t2[4] - '0');
            int diff = (h2 - h1)*60 + (m2 - m1);
            if(i == n - 1)//t2 becomes timePoints[0]
                diff += 60*24;
            res = min(res, diff);
        }
        return res;
    }
};
