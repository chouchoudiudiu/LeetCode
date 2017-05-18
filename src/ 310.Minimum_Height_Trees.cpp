class Solution {
public:
//topoligical sort, BFS
//一层一层的褪去叶节点，最后剩下的一个或两个节点就是我们要求的最小高度树的根节点
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> adjs(n);
        queue<int> q;
        vector<int> res;
        for (auto& e : edges) {
            adjs[e.first].insert(e.second);
            adjs[e.second].insert(e.first);
        }
        for (int i = 0; i < n; ++i) {
            if (adjs[i].size() == 1) //indgree == 0
                q.push(i);
        }
        while (n > 2) {
            int size = q.size();
            n -= size;//decrease n
            for (int i = 0; i < size; ++i) {
                int u = q.front();
                q.pop();
                for (auto v : adjs[u]) {
                    adjs[v].erase(u);
                    if (adjs[v].size() == 1)
                        q.push(v);
                }
            }
        }
        while (!q.empty()) {//only the last one or two nodes are selected roots
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};

//1
//[]
