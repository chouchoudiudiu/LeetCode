class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int low = 1, high = x, res, mid;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (mid <= x/mid) {
                low = mid + 1;
                res = mid;
            }
            else 
                high = mid - 1;
            
        }
        return res;
    }
};

////////////////////////////////////////////////////////////
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0)
            return 0;
        int low = 1, high = x;
        int mid = low + (high - low)/2;
        while (low <= high) {
            if (mid <= x/mid && (mid + 1)  > x/(mid + 1))
                return mid;
            else if(mid < x/mid)
                low = mid + 1;
            else 
                high = mid - 1;
            mid = low + (high - low)/2;
        }
        return mid;
    }
};

/*
2147395599 overflow, write * by / */
