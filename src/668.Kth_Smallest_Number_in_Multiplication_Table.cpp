class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        while(low < high) {
            int mid = low + (high - low)/2;
            if(count(mid, m, n) >= k)
                high = mid;
            else
                low = mid + 1;
        }
        return high; //low or high both fine since there are equal when quit
    }
    int count(int v, int m, int n) {
        int cnt = 0;
        for(int i = 1; i <= m; ++i) {
            int sum = min(v/i, n);
            cnt += sum;
        }
        return cnt;
    }
};

/*矩阵中小于等于mid 的数字的个数
This leaves us with the task of counting how many values are less than or equal to x.
For each of m rows, the i-th row looks like [i, 2*i, 3*i, ..., n*i], and there are min(x // i, n) 
values in that row that are less than or equal to x.*/
