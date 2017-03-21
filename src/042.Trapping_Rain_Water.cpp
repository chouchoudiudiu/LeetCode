class Solution {
public:
    int trap(vector<int>& height) {
        int peak = 0, area = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > height[peak])
                peak = i;
        }
        int left = 0;
        for (int i = 0; i < peak; ++i) {
            if (height[i] > height[left])
                left = i;
            else
                area += height[left] - height[i];
        }
        int right = height.size() - 1;
        for (int i = height.size() - 1; i > peak; --i) {
            if (height[i] > height[right])
                right = i;
            else
                area += height[right] - height[i];
        }
        return area;
    }
};
/*
[5,2,1,2,1,5]
*/
