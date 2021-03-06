class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        if(n == 1 && edges.size() == 0) //single node, no child
            return true;
        vector<vector<int>> adjs(n);
        for(auto e : edges) {
            adjs[e.first].push_back(e.second);
            adjs[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        return dfs(adjs, visited, edges[0].first, -1);
    }
    
    bool dfs(vector<vector<int>>& adjs, vector<bool>& visited, int u, int from) {
        if(visited[u])
            return false;
        visited[u] = true;
        for(auto v : adjs[u]) {
            if(v != from) {//不走回头路，现在在a 在 check a的邻居，比如b,c,d;到b时候，不再check a，才能一路往前，dfs
                if(!dfs(adjs, visited, v, u))
                    return false;
            }
        }
        return true;
    }
};

//https://leetcode.com/problems/graph-valid-tree/discuss/
