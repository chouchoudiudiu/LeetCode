class Solution {
public:
//standard union find + path compression
    int root(int i) {
        while (i != id[i]) {
            //id[i] = id[id[i]]; ////make every other node in path point to its grandparent, trees stay very flat
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) { //check if p and q have the same root
        return root(p) == root(q); 
    }
    void unite(int p, int q) { //change root of p to point to root of q
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m <= 0 || n <= 0)
            return res;
        id.resize(m*n);
        for (int i = 0; i < m*n; ++i)
            id[i] = -1;
        int cnt = 0;
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto pos : positions) {//adding one by one
            int r = pos.first, c = pos.second;
            int p = n * r + c;
            id[p] = p;
            ++cnt;
            for (int i = 0; i < 4; ++i) {
                int x = r + dir[i][0];
                int y = c + dir[i][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int q = n * x + y;
                    if (id[q] != -1 && !find(p, q)) {//not connected but they are neighbors
                        unite(p, q);//p is lonely island
                        --cnt;
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    vector<int> id; //id[i] is parent of i
};//add [1, 1] becomes 1
