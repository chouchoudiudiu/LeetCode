class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0)
            return 0;
        int same = 0, diff = k; //实际上d[i]只依赖于最后的d[i - 1]与d[i - 2]两个变量
        for(int i = 2; i <= n; i++) {
            int tmp = diff;
            diff = diff*(k - 1) + same*(k - 1); //same相当于之前的d[i - 2], diff相当于之前的d[i - 1]
            same = tmp;//前进一步，最新计算的变成了最新的diff
        }
        return same + diff;
    }
};

//假设3种颜色，算到i时候，i可以取与i-1不同的颜色，那么就是d[i - 1]*(k - 1)
//假设i与i-1取了相同的颜色，那么这个颜色必定是与d[i - 2]不管最后一个颜色是什么的颜色不同的一个颜色，k-1种

///////////////////////////////////////////////////////////
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        int d[n + 1] = {0};
        d[0] = 0;
        d[1] = k;
        d[2] = k*k;
        for(int i = 3; i <= n; i++)
            d[i] = d[i - 1]*(k - 1) + d[i - 2]*(k - 1);
        
        return d[n];
    }
};
