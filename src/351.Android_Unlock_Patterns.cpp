class Solution {
public:
    int dfs(int num, int len, int cnt, int m, int n, vector<vector<int>> &jump, vector<bool> &visited) {
        if (len >= m)
            ++cnt;
        if (len >= n)
            return cnt;
        visited[num] = true;
        for (int i = 1; i <= 9; ++i) {
            int j = jump[num][i];
            if (!visited[i] && (j == 0 || visited[j])) //j == 0, always good; visited[j] needs to be true when you need to jump
                cnt = dfs(i, len + 1, cnt, m, n, jump, visited);//count has been updated internally
        }
        visited[num] = false;
        return cnt;
    }

    int numberOfPatterns(int m, int n) {
        int cnt = 0;
        vector<bool> visited(10, false); //All the keys must be distinct.
        vector<vector<int>> jump(10, vector<int>(10, 0));
        
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[7][9] = jump[9][7] = 8;
        jump[3][9] = jump[9][3] = 6;
        jump[4][6] = jump[6][4] = 5;
        jump[2][8] = jump[8][2] = 5;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;
        
        cnt += dfs(1, 1, 0, m, n, jump, visited) * 4; //symmetric, len starts with 1
        cnt += dfs(2, 1, 0, m, n, jump, visited) * 4; //symmetric,
        cnt += dfs(5, 1, 0, m, n, jump, visited); //因为要乘以4，无法将count作为内部&
        
        return cnt;
    }
};
