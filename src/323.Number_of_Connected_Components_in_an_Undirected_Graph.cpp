class Solution {
public:
//standard union find + root compression
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]]; //make every other node in path point to its grandparent, trees stay very flat
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) { //check if p and q have the same root
        return root(p) == root(q);
    }
    void unite(int p, int q) {  //change root of p to point to root of q
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        for (int i = 0; i < n; ++i)
            id.push_back(i);
        for (auto e : edges) {
            int p = e.first;
            int q = e.second;
            if (!find(p, q)) {
                unite(p, q);
                --n;
            }
        }
        return n;
    }
    vector<int> id;
};

/////////////////////////
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if(edges.empty() && n >= 0)
            return n;
        unordered_map<int, vector<int>> m; //id and its edges starting from it
        for(auto e : edges) {
            m[e.first].push_back(e.second);
            m[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        int cc = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                bfs(m, visited, i);
                ++cc;
            }
        }
        return cc;
    }
    
    void bfs(unordered_map<int, vector<int>>& m, vector<bool>& visited, int i) {
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int p = q.front();
            q.pop();
            visited[p] = true;
            for(auto v : m[p]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};
