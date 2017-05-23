class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        long long x = 1;
        for (int d = 64; d >= 2; --d) {
            if ((x<<d) >= num)//只找同一个量级
                continue;
            long long left = 2, right = pow(num, 1.0 / d) + 1;
            while (left <= right) {
                long long mid = left + (right - left)/2, cur = 1, sum = 1;
                for (int j = 1; j <= d; ++j) {
                    cur *= mid;
                    sum += cur;
                }
                if (sum == num)
                    return to_string(mid);
                else if (sum < num)
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return to_string(num - 1);
    }
};
//"470988884881403701"
 //等比数列 n = 1 + k + ...k ^(d - 1) = (k^d - 1)/(k - 1) 不过不知为何不太对。。。n最小是3，k最小是2
 //k最小是2，那么d最大只能为log2(n + 1)
