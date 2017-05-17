class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        for (auto v : prerequisites)
            inDegree[v.first]++;
        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ordered;
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;
            ordered.push_back(u);
            for (auto v : prerequisites) {
                if (v.second == u) {//the courses rely on u
                    if (--inDegree[v.first] == 0) {
                        q.push(v.first);
                    }
                }
            }
        }
        if (cnt == numCourses) 
            return ordered;
        else
            return {}; //cycle detected, can not finish
    }
};

//need to write DFS too
