class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
            int n = flights.size(), k = days[0].size();
            vector<vector<int>> mem(n, vector<int>(k, 0));
            return helper(flights, days, 0, 0, mem);
    }
    int helper(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week, vector<vector<int>>& mem) {
        int n = flights.size(), k = days[0].size(), res = 0;
        if(week == k)
            return 0;
        if(mem[city][week] > 0)
            return mem[city][week];
        for(int i = 0; i < n; ++i) {
            if(i == city || flights[city][i] == 1)
                res = max(res, days[i][week] + helper(flights, days, i, week + 1, mem));
        }
        return mem[city][week] = res;
    }
};

////////////////////////////////////////////////
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
            int n = flights.size(), k = days[0].size();
            vector<vector<int>> f(k + 1, vector<int>(n, INT_MIN));
            f[0][0] = 0;
            for(int i = 1; i <= k; ++i) {
                for(int v = 0; v < n; ++v)
                    for(int u = 0; u < n; ++u) {
                        if(u == v || flights[u][v] == 1)
                            f[i][v] = max(f[i][v], f[i - 1][u] + days[v][i - 1]);
                    }
            }
        
            return *max_element(f[k].begin(), f[k].end());
    }
};

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
            int n = flights.size(), k = days[0].size();
            vector<int> f(n, INT_MIN);
            f[0] = 0;
            for(int i = 0; i < k; ++i) {
                vector<int> t(n, INT_MIN);
                for(int v = 0; v < n; ++v)
                    for(int u = 0; u < n; ++u) {
                        if(u == v || flights[u][v] == 1)
                            t[v] = max(t[v], f[u] + days[v][i]);
                    }
                f = t;
            }
        
            return *max_element(f.begin(), f.end());
    }
};

//can further reduce the space
/*
我们新建一个临时数组t，初始化为整型最小值，然后遍历每一个城市，对于每一个城市，我们遍历其他所有城市，看是否有飞机能直达当前城市，或者就是当前的城市，我们用dp[p] + days[i][j]来更更新dp[i]，当每个城市都遍历完了之后，我们将t整个赋值给dp，然后进行下一周的更新，最后只要在dp数组中找出最大值返回即可
*/
//can further reduce the space
解题思路：
动态规划（Dynamic Programming）

dp[w][c]表示第w周选择留在第c个城市可以获得的最大总收益

初始令dp[w][0] = 0, dp[w][1 .. c - 1] = -1

当dp[w][c] < 0时，表示第c个城市在第w周时还不可达。
状态转移方程：

for w in (0 .. K)
    for sc in (0 .. N)
        if dp[w][sc] < 0:
            continue
        for tc in (0 .. N)
            if sc == tc or flights[sc][tc] == 1:
                dp[w + 1][tc] = max(dp[w + 1][tc], dp[w][sc] + days[tc][w])
