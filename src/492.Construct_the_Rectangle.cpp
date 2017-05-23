class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width;
        for (width = sqrt(area); width >= 1; --width) {
            if (width * (area/width) == area)
                break;
        }
        return {area/width, width};
    }
};
