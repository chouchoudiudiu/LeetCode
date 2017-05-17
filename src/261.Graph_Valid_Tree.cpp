class Solution {
public:
    bool findCycle(vector<vector<int>>& adjs, vector<bool>& visited, int u, int from) {
        visited[u] = true;
        for (auto w : adjs[u]) {
            if (!visited[w])
                findCycle(adjs, visited, w, u); //w will be set to visited in call
            else {
                if(w != from)
                    return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        if(n == 1 && edges.size() == 0)//single node, no child
            return true;
        vector<vector<int>> adjs(n);
        for (auto e : edges) {
            adjs[e.first].push_back(e.second);
            adjs[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        bool hasCycle = findCycle(adjs, visited, edges[0].first, edges[0].first);
        return !hasCycle;
        //visited check covered by first line? otherwise won't satisfy; may check every visited is true
    }
};

//can solve by BFS or UnionFind too
//Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
//Make sure every node is reached - this has to be a connected graph;
