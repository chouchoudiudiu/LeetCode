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

//can further reduce the space
