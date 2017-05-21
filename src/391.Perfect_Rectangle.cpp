class Solution {
public: //unordered_set<pair<int, int> not work...need hash
    void processCorner(unordered_set<string>& corners, string s) {
        if (corners.find(s) == corners.end())
            corners.insert(s);
        else
            corners.erase(s);
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0;
        int xMin = INT_MAX, yMin = INT_MAX, xMax = INT_MIN, yMax = INT_MIN;
        unordered_set<string> corners;
        for (auto rect : rectangles) {
            area += (rect[2] - rect[0])*(rect[3] - rect[1]);
            xMin = min(xMin, rect[0]);
            xMax = max(xMax, rect[2]);
            yMin = min(yMin, rect[1]);
            yMax = max(yMax, rect[3]);
            
            processCorner(corners, to_string(rect[0]) + " " + to_string(rect[1]));
            processCorner(corners, to_string(rect[0]) + " " + to_string(rect[3]));
            processCorner(corners, to_string(rect[2]) + " " + to_string(rect[1]));
            processCorner(corners, to_string(rect[2]) + " " + to_string(rect[3]));
        }
        
        if (corners.size() != 4 ||
            corners.count(to_string(xMin) + " " + to_string(yMin)) != 1 ||
            corners.count(to_string(xMax) + " " + to_string(yMin)) != 1 ||
            corners.count(to_string(xMin) + " " + to_string(yMin)) != 1 ||
            corners.count(to_string(xMax) + " " + to_string(yMax)) != 1 )
            return false;
        //found one, erase one 抵消; 最后set中应该只剩下最后四个corner(且仅出现一次)
        //four corners appears once, all other points exists twice or four times, even
        return area == (xMax - xMin)*(yMax - yMin);
    }
};
