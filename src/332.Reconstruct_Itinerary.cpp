class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m; //edges, from to
        for (auto t : tickets) {
            m[t.first].insert(t.second);
        }
        dfs(m, res, "JFK");
        return vector<string>(res.rbegin(), res.rend());
    }
    
    void dfs(unordered_map<string, multiset<string>>& m, vector<string>& res, string from) {
        while (!m[from].empty()) {
            string s = *(m[from].begin());
            m[from].erase(m[from].begin()); //not s
            dfs(m, res, s);
        }
        res.push_back(from); //直到它要到的to都已经到过了，empty
    }
};
//need while condition to go out loop, graph动态变化中;  how about if?
//[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]] if fails ["JFK","KUL"] ! KUL not flying anywhere else
//while. otherwise may visit a set that has already been erased (empty, could have been erased in deeper dfs)
//topological sort, 之前是要找遍历所有顶点，现在要遍历所有的边 (找到一条经过所有边的路径)
//multiset允许重复插入元素，且自动排序
