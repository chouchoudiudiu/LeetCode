class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sqrt(i); ++j) { //backwards or forwards
                dp[i] =  min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return dp[n];
    }
};

//bfs
class Solution {
public:
    int numSquares(int n) {
        int steps = 0;
        queue<int> q;
        q.push(n);
        vector<bool> visited(n, false);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                int top = q.front();
                q.pop();
                if(top == 0)
                    return steps;
                for(int j = 1; j <= sqrt(top); ++j) {
                    int val = top - j*j;
                    if(!visited[val]) {
                        q.push(val);
                        visited[val] = true;
                    }
                }
            }
            ++steps;
        }
        return steps;
    }
};
