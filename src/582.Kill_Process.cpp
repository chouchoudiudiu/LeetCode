class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, unordered_set<int>> m;
        for(int i = 0; i < ppid.size(); ++i) {
            m[ppid[i]].insert(pid[i]);
        }
        queue<int> q;
        q.push(kill);
        while(!q.empty()) {
            int id = q.front();
            q.pop();
            res.push_back(id);
            for(auto v : m[id]){
                q.push(v);
            }
        }
        return res;
    }
};
