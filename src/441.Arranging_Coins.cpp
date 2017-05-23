class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) return 0;
        int low = 1, high = n, mid;
        while (low <= high) {
            int mid = low + (high - low)/2;
            long long sum1 = mid*(mid + 1.0)*0.5;
            long long sum2 = (mid + 1.0)*(mid + 2.0)*0.5;
            if (n >= sum1 && n < sum2)
                return mid;
            else if (sum1 > n)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return mid;
    }
};

//float
