class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty())
            return 0;
        int m = image.size(), n = image[0].size();
        int left = searchCols(0, y, 0, m - 1, image, true);
        int right = searchCols(y, n - 1, 0, m - 1, image, false);
        int top = searchRows(left, right, 0, x - 1, image, true);
        int bottom = searchRows(left, right, x + 1, m - 1, image, false); 
        return (right - left) * (bottom - top); //l r t b : 1 3 0 3
    }
//searchCols and searchRows can combine   
    int searchCols(int low, int high, int top, int bottom, vector<vector<char>>& image, bool oneToZero) {
        while (low <= high) {
            int mid = low + (high - low)/2, i = top;
            for (; i <= bottom; ++i) {
                if (image[i][mid] == '1')
                    break;
            }
            if (i <= bottom == oneToZero)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
//oneToZero 0 1找到1的位置（low往右跳过），反之， 1 0 找到了0的位置（low 往右跳过）
    int searchRows(int left, int right, int low, int high, vector<vector<char>>& image, bool oneToZero) {
        while (low <= high) {
            int mid = low + (high - low)/2, i = left;
            for (; i <= right; ++i) {
                if (image[mid][i] == '1')
                    break;
            }
            if (i <= right == oneToZero)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
}; 
