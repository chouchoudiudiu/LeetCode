class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            int val = matrix[mid/n][mid%n]; //mid/n
            if (val == target)
                return true;
            if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

////////////////////////////////////////////////////////////////
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = n - 1;
        while (i <= m - 1 && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target)
                ++i;
            else 
                --j;
        }
        return false;
    }
};
