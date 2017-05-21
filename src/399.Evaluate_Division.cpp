class Solution {
public:
    bool dfs(unordered_set<string>& visited, string src, string dst, double& res) {
        if (src == dst)
            return true;
        bool found = false;
        visited.insert(src);
        for (auto v : graph[src]) {
            if (visited.find(v.first) == visited.end()) {
                res *= v.second;
                found = dfs(visited, v.first, dst, res);
                if (found)
                    return true;
                else
                    res /= v.second; // this path didn't go through
            }
        }
        return found;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        if (equations.size() == 0 || equations.size() != values.size())
            return res;
        for (int i = 0; i < equations.size(); ++i) {
            string v1 = equations[i].first;
            string v2 = equations[i].second;
            graph[v1].push_back({v2, values[i]});
            graph[v2].push_back({ v1, 1 / values[i] });
        }
        for (auto q : queries) {
            unordered_set<string> visited; //每次一个新的,记录访问过的顶点
            double ans = 1.0;
            bool reached = dfs(visited, q.first, q.second, ans);
            if (!reached || !graph.count(q.first) || !graph.count(q.second))
                res.push_back(-1.0);
            else
                res.push_back(ans);
        }
        return res;
    }
    private:
        unordered_map<string, vector<pair<string, double>>> graph;
};
/*
[ ["a","b"],["b","c"] ]
[2.0,3.0]
[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]
*/
