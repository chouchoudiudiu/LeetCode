class Solution {
public:
//binary search to find sqrt(x)
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num/i; ++i) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};

//2147483647 TLE
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid*mid == num)
                return true;
            else if(mid < num/mid)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return false;
    }
};

//binary search to find sqrt(x)
