class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty())
            return 0;
        int m = image.size(), n = image[0].size();
        int left = bsearch(0, y, 0, m - 1, image, true, true);
        int right = bsearch(y, n - 1, 0, m - 1, image, false, true);
        int top = bsearch(0, x, left, right, image, true, false);
        int bottom = bsearch(x, m - 1, left, right, image, false, false);
        return (right - left) * (bottom - top); //l r t b : 1 3 0 3
    }
    int bsearch(int low, int high, int min, int max, vector<vector<char>>& image, bool oneToZero, bool horizontal) {
        while(low <= high) {
            int mid = low + (high - low)/2, i = min;
            for(; i <= max; ++i) {
                int val = horizontal ? image[i][mid] : image[mid][i];
                if(val == '1')
                    break;
            }
            if(i <= max == oneToZero)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
//oneToZero 0 1找到1的位置（low往右跳过），反之， 1 0 找到了0的位置（low 往右跳过）
}; 

//right and bottom 都是要多1，所以最后是(right - left) * (bottom - top);
